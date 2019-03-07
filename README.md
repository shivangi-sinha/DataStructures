# DataStructures
Data Structures in C

## Implementation of Circular Linked List Deque

In this file, I have implemented t the Deque ADT with a Circularly-Doubly-Linked List with a Sentinel.
The sentinel is a special link, does not contain a value, and should not be removed. Using a sentinel makes some linked 
list operations easier and cleaner in implementation. This list is circular, meaning the end points back to the beginning,
thus one sentinel suffices (the last item should point to the sentinel as its next,and the sentinel's prev should be the 
last item,sentinel's next is the first item).  The header file and the implementation file for this approach are [cirListDeque.h](https://github.com/shivangi-sinha/DataStructures/blob/master/cirListDeque.c) and [cirListDeque.c](https://github.com/shivangi-sinha/DataStructures/blob/master/cirListDeque.c), respectively. Complete the functions in cirListDeque.c
anda test harness in testCirListDeque.c to test the functionality of  Circularly-Doubly-Linked List deque.



## Binary Search Iterator with In-order transversal

In these files I have implemented an iterator that returns values from a BST in the same order they would be visited in an in-order traversal of 
the tree. For a BST, this will be equivalent to ascending sorted order. 
