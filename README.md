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
<pre>
0: ms(0;7)
1:    ms(0;3)
2:          ms(0;1)
3:              ms(0;0)
3:              ms(1;1)
3:              m(0;0;1)
2:          ms(2;3)
3:              ms(2;2)
3:              ms(3;3)
3:              m(2;2;3)
2:          m(0;1;3)
1:    ms(4;7)
2:          ms(4;5)
3:              ms(4;4)
3:              ms(5;5)
3:              m(4;4;5)
2:          ms(6;7)
3:              ms(6;6)
3:              ms(7;7)
3:              m(6;6;7)
2:          m(4;5;7)
1:    m(0;3;7)
</pre>

