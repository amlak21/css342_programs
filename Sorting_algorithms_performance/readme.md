Program description from my professor

Purpose 
 
This lab will serve two purposes.  First, it will provide hands-on experience for utilizing many of 
the sorting algorithms we will introduce in the class.  Second, it will viscerally demonstrate the 
cost of O(n2) v. O(n logn) algorithms.  It will also clearly show that algorithms with the same 
complexity may have different running times. 
 
Problem:  
 
You will write a program which implements the following sorts and compares the performance 
for operations on vectors of integers of growing sizes 10, 100, 1000, 5000, 10000, 25000, etc....  
You will graph the performance of the different sorts as a function of the size of the vector. 
 
1) BubbleSort 
2) InsertionSort 
3) MergeSort 
4) Non-Recursive, one extra vector<int> MergeSort (We’ll call this improved version, 
IterativeMergeSort from here on out in this homework) 
5) QuickSort 
6) ShellSort 
 
 
Details: 
 
IterativeMergeSort 
 
 In-place sorting refers to sorting that does not require extra memory vectors.   For 
example, QuickSort performs partitioning operations by repeating a swapping operation on two 
data items in a given vector.  This does not require an extra vector. 
MergeSort as shown in Carrano allocates a temporary vector at each recursive call.  Due 
to this MergeSort is slower than QuickSort even though their running time is upper-bounded to 
O(n log n).  
We can improve the performance of MergeSort by utilizing a non-recursive method and 
using only one additional vector (instead of one vector on each recursive call).   In this improved 
version of MergeSort, IterativeMergeSort, one would merge data from the original vector into 
the additional vector and alternatively copy back and forth between the original and the 
additional temporary vector.   Please re-read the last sentence as it is critical to the grading of 
the lab. 
For the IterativeMergeSort we still need to allow data items to be copied between the 
original and this additional vector as many times as O(log n).  However, given the iterative 
nature we are not building up state on the stack. 
  
 
Other Sorts 
 BubbleSort, InsertionSort, MergeSort, and QuickSort are well documented and you 
should implement them with the aid of examples in the Carrano book and class.   We have gone 
over Shell Sort in class. 
 
 
Runtime Details 
 Your program, called sorter, will take in two parameters:  
1) sort type as a string of characters  
2) an vector size as an integer.   
 
Your program will create and sort an vector<int> of the size with the specified sort:  
MergeSort, BubbleSort, InsertionSort, QuickSort, ShellSort or IterativeMergeSort.  The driver 
functions below will help with the creation. 
 
 Examples: 
  sorter MergeSort 100  (creates and sorts a vector<int> of size 100 using 
MergeSort) 
 
  sorter QuickSort 1000 (creates and sorts a vector<int> of size 1000 using 
QuickSort) 
 
  sorter IterativeMergeSort 10000 (creates and sorts a vector<int> of 10000 using 
the newly implemented non-recursive semi-in-place MergeSort)