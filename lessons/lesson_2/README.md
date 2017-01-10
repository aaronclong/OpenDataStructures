#(Chaper Two)[http://opendatastructures.org/ods-cpp/2_7_Discussion_Exercises.html]’s Exercises as defined on 08/01/2017

- [] Exercise 2.1. The List method addAll(i,c) inserts all elements of the Collection c into the list at position i. (The add(i, x) method is a special case where c = {x}.) Explain why, for the data structures in this chapter, it is not efficient to implement addAll(i,c) by repeated calls to add(i,x). Design and implement a more efficient implementation.
- [] Exercise 2.2. Design and implement a RandomQueue. This is an imple- mentation of the Queue interface in which the remove() operation removes an element that is chosen uniformly at random among all the elements currently in the queue. (Think of a RandomQueue as a bag in which we can add elements or reach in and blindly remove some random element.) The add(x) and remove() operations in a RandomQueue should run in con- stant time per operation.
- [] Exercise 2.3. Design and implement a Treque (triple-ended queue). This is a List implementation in which get(i) and set(i,x) run in constant time and add(i, x) and remove(i) run in time O(1+min{i,n−i,|n/2−i|}) .




In other words, modifications are fast if they are near either end or near the middle of the list.
- [] Exercise 2.4. Implement a method rotate(a, r) that “rotates” the array a so that a[i] moves to a[(i + r) mod a.length], for all i ∈ {0, . . . , a.length}.
- [] Exercise 2.5. Implement a method rotate(r) that “rotates” a List so that list item i becomes list item (i + r) mod n. When run on an ArrayDeque, or a DualArrayDeque, rotate(r) should run in O(1 + min{r, n − r}) time.

- [] Exercise 2.6. Modify the ArrayDeque implementation so that the shift- ing done by add(i,x), remove(i), and resize() is done using the faster System.arraycopy(s,i,d,j,n) method.
- [] Exercise 2.7. Modify the ArrayDeque implementation so that it does not use the % operator (which is expensive on some systems). Instead, it should make use of the fact that, if a.length is a power of 2, then
k%a.length=k&(a.length−1) . (Here, & is the bitwise-and operator.)
- [] Exercise 2.8. Design and implement a variant of ArrayDeque that does not do any modular arithmetic at all. Instead, all the data sits in a con- secutive block, in order, inside an array. When the data overruns the beginning or the end of this array, a modified rebuild() operation is per- formed. The amortized cost of all operations should be the same as in an ArrayDeque.



Hint: Getting this to work is really all about how you implement the rebuild() operation. You would like rebuild() to put the data structure into a state where the data cannot run off either end until at least n/2 operations have been performed.



Test the performance of your implementation against the ArrayDeque. Optimize your implementation (by using System.arraycopy(a,i,b,i,n)) and see if you can get it to outperform the ArrayDeque implementation.
- [] Exercise 2.9. Design and implement a version of a RootishArrayStack that has only O(√n) wasted space, but that can perform add(i,x) and remove(i, x) operations in O(1 + min{i, n − i}) time.
- [] Exercise 2.10. Design and implement a version of a RootishArrayStack that has only O(√n) wasted space, but that can perform add(i,x) and remove(i, x) operations in O(1 + min{√n, n − i}) time. (For an idea on how to do this, see Section 3.3.)
- [] Exercise 2.11. Design and implement a version of a RootishArrayStack that has only O(√n) wasted space, but that can perform add(i,x) and remove(i,x)operationsinO(1+min{i,√n,n−i})time. (SeeSection3.3 for ideas on how to achieve this.)
- [] Exercise 2.12. Design and implement a CubishArrayStack. This three level structure implements the List interface using O(n2/3) wasted space. In this structure, get(i) and set(i,x) take constant time; while add(i,x) and remove(i) take O(n1/3) amortized time.