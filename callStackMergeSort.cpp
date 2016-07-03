/*
This program illustrates the function calls to mergesort and merge 
in a multiple recursive implementation. Each single call 
is displayed in a line, along with the arguments 
(the start and end indeces of the original array
to be sorted). 

For example, the input array [14,7,3,12,9,11,8,10] will be sorted in the following 
way: 
We first call mergesort with array[0..7] (ie the whole array).
Within this call, mergesort is called again ms(0;3) with array[0..3] 
and so on. After the ms(0;3) exits, the algorithm continues 
with array[4..7], which is displayed at the same level as ms(0;3). 
The numbers on the left denote the depth of the function call 
in the stack, which equals one for ms(0;3), ms(4,7) and merge(0;3;7).

0: ms(0;7)
1:        ms(0;3)
2:               ms(0;1)
3:                      ms(0;0)
3:                      ms(1;1)
3:                      m(0;0;1)
2:               ms(2;3)
3:                      ms(2;2)
3:                      ms(3;3)
3:                      m(2;2;3)
2:               m(0;1;3)
1:        ms(4;7)
2:               ms(4;5)
3:                      ms(4;4)
3:                      ms(5;5)
3:                      m(4;4;5)
2:               ms(6;7)
3:                      ms(6;6)
3:                      ms(7;7)
3:                      m(6;6;7)
2:               m(4;5;7)
1:        m(0;3;7)
[3,7,8,9,10,11,12,14]
*/

#include <iostream>
using namespace std;

// Takes in an array that has two sorted subarrays,
//  from [p..q] and [q+1..r], and merges the array
string blanks(int depth){
    
    string resu;
    for(int i=0; i<depth*7;i++){
	resu.push_back(' ');
    }
    return resu;
};

void merge(int* array, int p,int  q,int r,int depth){
	
	cout<<depth<<":"<<blanks(depth)<<" m("<<p<<";"<<q<<";"<<r<<")"<<"\n";
    int lowHalf [q-p+1];
    int highHalf [r-q];

    int k = p;
    int i;
    int j;
    for (i = 0; k <= q; i++, k++) {
        lowHalf[i] = array[k];
    }
    for (j = 0; k <= r; j++, k++) {
        highHalf[j] = array[k];
    }

    k = p;
    i = 0;
    j = 0;
    
    // Repeatedly compare the lowest untaken element in
    // lowHalf with the lowest untaken element in highHalf
    // and copy the lower of the two back into array
    while( i <(q-p+1) && j<(r-q) ){
        if(lowHalf[i] <= highHalf[j]){
            array[k] = lowHalf[i];
            i++;
        }else{
            array[k] = highHalf[j];
            j++;
        }
        k++;
    }
    
    // Once one of lowHalf and highHalf has been fully copied
    //  back into array, copy the remaining elements from the
    //  other temporary array back into the array
    while(i <(q-p+1)){
     array[k] = lowHalf[i];
        k++;
        i++;    
    }
    while(j <(r-q)){
     array[k] = highHalf[j];
        k++;
        j++;    
    }
};

// Takes in an array and recursively merge sorts it
void mergeSort(int* array,int p,int r,int depth){
  
  cout<<depth<<":"<<blanks(depth)<<" ms("<<p<<";"<<r<<")"<<"\n";
  if(p<r){
    int midpoint = (p+r)/2;
    mergeSort(array ,p , midpoint , depth+1);
    mergeSort(array, midpoint+1,r , depth+1);
    merge(array, p , midpoint, r,depth+1);
   }
};
void printArray(int * array , int L){
	cout <<"[" ;
	for(int i =0 ; i <L ;i++){
	cout<<array[i]<< (i==L-1 ? "":"," );
	}cout<< "]"<<endl;
};

int main(){
	int array [8]= {14, 7, 3, 12, 9, 11,8,10};
	cout<< "input array:"<<endl;
	printArray(array,8);
	mergeSort(array, 0, 7,0);
	cout<< "sorted array:"<<endl;
	printArray(array,8);
}
