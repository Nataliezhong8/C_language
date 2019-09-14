/*pqSort.c: use a priority queue to sort an array of integers
 into descending order
 */

#include "pq.h"

int main() {
    int a[] = {41, 2, 58, 156, 360, 81, 260, 74, 167, 13};
    int len = sizeof(a) / sizeof(a[0]);
    PQ pq;
    pq = createpq(len);
    printf("Array: ");
    for (int i = 0; i < len; i++) {
        printf("%d ", a[i]);
        insertpq(a[i], pq);
    }
    printf("\nSorted array: ");
    while (!isEmpty) {
        int val = delMax(pq);
        printf("%d ", val);
    }
    putchar('\n');
    return 0;
}