//pq.h
//yinghong zhong 
//15/07/2019

/* 1.create an abstract data structure
2.insert an element into the structure(stacks and queues use push and qush)
3.delete an element from the structure(stacks and queues use pop)
4.check whether the structure is empty*/
#include <stdio.h>
#include <stdlib.h>

typedef struct pqstruct *PQ;

//function: create a priority queue
//args: the length of the queue
//return: a pointer PQ
PQ createpq(int len);

//function: insert an element to the priority queue
//args: value of the element, a priority queue
//return: void
void insertpq(int val, PQ pq);

//function: delete the max number in pq
//args: a priority queue
//return: the value of the max element
int delMax(PQ pq);

//function: check if the priority queue is empty
//args: a priority queue
//return: return 1 if it is empty, else return 0
int isEmpty(PQ pq);