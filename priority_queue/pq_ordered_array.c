/*pq_ordered_array.c 
1. data are stored in an ordered array(increasing)
2. when insert an element, complexity is O(n); when delmax is O(1) 
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
/*1. find the index i where array[i] < val < array[i+1]
2. move the element after i+1 backward for 1
3. insert val in the index i
 */
void insertpq(int val, PQ pq) {
    if (pq == NULL) {
        fprintf (stderr, "insertpq: Not initialized...\n");
        exit(1);
    } 
    if (pq->array == NULL) {
        fprintf (stderr, "insertpq: Not initialized...\n");
        exit(1);
    }
    if (pq->count == 0) { //first element
        *(pq->array) = val;
    } else if (pq->count == 1) { //second element
        if (*(pq->array) <= val) {
            *(pq->array + 1) = val;
        } else {
            int next = *(pq->array);
            *(pq->array) = val;
            *(pq->array + 1) = next;
        }
    } else { //more than 2 elements
        if (val >= *(pq->array + pq->count)) { //if val has the largest value
            *(pq->array + pq->count + 1) = val;
        } else if (val < *(pq->array)){ //if val is the smallest one
            for (int i = 1; i < pq->count; i++) {
                int next = *(pq->array + i);
                *(pq->array + i) = *(pq->array + i - 1);
                *(pq->array + i + 1) = next;
            }
            *(pq->array) = val;
        } else {
            for (int i = 0; i < (pq->count - 1); i++) {
                if (*(pq->array + i) <= val && *(pq->array + i + 1) >= val) {
                    for (int j = i+2; j < pq->count; j++) {
                        int next = *(pq->array + j);
                        *(pq->array + j) = *(pq->array + j - 1);
                        *(pq->array + j + 1) = next;
                    }
                    *(pq->array + i) = val;
                }
            }
        }     
    }
    pq->count++;
    return;
}

//function: delete the max number in pq(last one)
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
    int retval = *(pq->array + pq->count);
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