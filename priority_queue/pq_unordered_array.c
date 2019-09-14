/*pq_unordered_array.c 
1. data are stored in an unordered array
2. when insert an element, complexity is O(1); when delmax is O(n) 
*/
//yinghong zhong 
//15/07/2019
#include "pq.h"

struct pqstruct {
    int length;
    int count;
    int *array;
};

//function: create a priority queue
PQ createpq(int len) {
    PQ pq;
    pq = (PQ)malloc(sizeof(struct pqstruct));
    if (pq == NULL) {
        fprintf (stderr, "createpq: No memory, aborting...\n");
        exit(1);
    } 
    pq->length = len;
    pq->count = 0;
    pq->array = (int*)malloc(sizeof(int) * len);
    if (pq->array == NULL) {
        fprintf (stderr, "createpq: No memory, aborting...\n");
        exit(1);
    }
    return pq; 
}

//function: insert an element to the priority queue
void insertpq(int val, PQ pq) {
    if (pq == NULL) {
        fprintf (stderr, "insertpq: Not initialized...\n");
        exit(1);
    } 
    if (pq->array == NULL) {
        fprintf (stderr, "insertpq: Not initialized...\n");
        exit(1);
    }
    *(pq->array + pq->count) = val;
    pq->count++;
    return;
}

//function: delete the max number in pq
int delMax(PQ pq) {
    if (pq == NULL) {
        fprintf (stderr, "delMax: Not initialized...\n");
        exit(1);
    } 
    if (pq->array == NULL) {
        fprintf (stderr, "delMax: Not initialized...\n");
        exit(1);
    } 
    //in unordered queue,use the last element to replace the max element
    int last = pq->count - 1; 
    int max = 0;
    for (int i = 1; i < pq->count; i++ ) {
        if (*(pq->array + i) > *(pq->array + max)) {
            max = i;
        }
    }
    int retval = *(pq->array + max);
    *(pq->array + max) = *(pq->array + last); //change the last number to the max value index
    
    /*  move the element up 1 after find the max value
    int retval = *(pq->array); //assume that the first element is the largest one
    int index = 0;
    for (int i = 1; i < pq->count; i++ ) {
        if (*(pq->array + i) > retval) {
            retval = *(pq->array + i);
            index = i;
        }
    }
    for (int j = index; j < (pq->count - 1); j++) {
        *(pq->array + j) = *(pq->array + j+1); //move the element up 1
    }
    */  
    pq->count--;
    return retval;
}


//function: check if the priority queue is empty
int isEmpty(PQ pq) {
    if (pq == NULL) {
        fprintf (stderr, "isEmpty: Not initialized...\n");
        exit(1);
    } 
    if (pq->array == NULL) {
        fprintf (stderr, "isEmpty: Not initialized...\n");
        exit(1);
    }
    if (pq->count == 0) {
        return 1;
    } else {
        return 0;
    }
}

