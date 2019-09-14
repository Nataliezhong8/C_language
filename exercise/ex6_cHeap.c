//args2heap.h
//yinghong zhong
//12/07/2019

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct list {
	int *array;
	int maxsize; 
	int count; //the actual number of node in heap
};

typedef struct list *HEAP;

//function: initialize a heap 
//arg: max size of a heap
//return: a heap tree
HEAP create(int size) {
	HEAP h;
	h = (HEAP)malloc(sizeof(struct list));
	if (h == NULL) {
	    fprintf(stderr,"createHEAP: no memory, aborting...\n");
	    exit(1);
	}
	h->array = (int*)malloc(sizeof(int) * (size+1));
	if (h->array == NULL) {
	    fprintf(stderr,"createArray: no memory, aborting...\n");
	    exit(1);
	}
	*(h->array) = '#';
	h->count = 0;
	h->maxsize = size;
	
	return h;
}

//function: fixup the new element child
//arg: index of child
void fixup(int *heap, int child) {
	while(child > 1 && (*(heap + child) > *(heap + child/2))) {
	    int swap = *(heap + child/2);
	    *(heap + child/2) = *(heap + child); //swap the child and parent's value
	    *(heap + child) = swap;
	    child = child/2;
	}
	return;
}

//function: fixdown the new element parent
//arg: HEAP h, index of parent node, number of node
void fixdown(int *heap, int parent, int count) {
	int finish = 0;
	while (2*parent <= count && !finish) {
	    int child = 2 * parent;
	    if (*(heap + child) < *(heap + child + 1) && child < count) { //choose a larger child node
		child++;
	    }
	    if (*(heap+parent) < *(heap+ child)) {
	        int swap = *(heap+ child);
			*(heap+ child) = *(heap+parent);
			*(heap+parent) = swap;
			parent = child;
	    } else {
			finish = 1;
		}
	}
	return;
}

//function: insert a number into a MaxHeap(should be ordered in a maxheap order HOP)
//arg: HEAP h, int num
//return:void
void insertHeap(HEAP h, int num) {
	if (h == NULL) {
	    fprintf(stderr,"insertHEAP: no memory, aborting...\n");
	    exit(1);
	}
	if (h->array == NULL) {
	    fprintf(stderr,"insertArray: no memory, aborting...\n");
	    exit(1);
	}
	if (h->count > h->maxsize) {
	    fprintf(stderr,"insert: full heap...\n");
	    exit(1);
	}
	h->count++; 
	int count = h->count;
	*(h->array + count) = num;
	fixup(h->array, h->count);
	return;
}

//function:delete the root of the heap and reorder it to satisfy HOP
//arg: HEAP h
//return: max value of heap
int delMax(HEAP h) {
	if (h == NULL) {
	    fprintf(stderr,"delHEAP: no memory, aborting...\n");
	    exit(1);
	}
	if (h->array == NULL) {
	    fprintf(stderr,"delArray: no memory, aborting...\n");
	    exit(1);
	}
	if (h->count == 0) {
	    fprintf(stderr,"del: empty heap...\n");
	    exit(1);
	}
	int retval = *(h->array + 1); //the value of root
	*(h->array + 1) = *(h->array + h->count);
	h->count--;
 	fixdown(h->array, 1, h->count);
	return retval;
}

void print(HEAP h) {
	if (h == NULL) {
	    fprintf(stderr,"delHEAP: no memory, aborting...\n");
	    exit(1);
	}
	if (h->array == NULL) {
	    fprintf(stderr,"delArray: no memory, aborting...\n");
	    exit(1);
	}
	printf("Heap is: ");
	for (int i = 0; i <= h->count; i++) {
		printf("%c ", *(h->array + i));
	}
	printf("\n");
	return;
}


int main(int argc, char *argv[]) {
    if (argc > 1) {
        int size = argc - 1;
        int *number;
        number = (int*)malloc(sizeof(int) * size);
        if (number == NULL) {
            fprintf (stderr,"No memory...\n");
            exit(1);
        }
        for (int i = 1; i <= size; i++) {
            /* if (strlen(argv[i]) == 1) { //a single character
                char *n = argv[i];
                int val = *n - '0';
                char m = val + '0';

                if (isalnum(m)) {
                    *(number+i-1) = m ;
                }
            }*/  //actually argv[i] is a pointer pointing to the first letter of the string
			 if(isalnum(*argv[i]) && strlen(argv[i]) == 1) {
				*(number+i-1) = *argv[i];
			}

        }
        HEAP h = create(size);
        for (int i = 0; i < size; i++) {
            insertHeap(h,*(number+i));
        }
        print(h);
    }
	return 0;
}

