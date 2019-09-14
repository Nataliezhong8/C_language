//quack.c: an interface definition for a stack/ queue
#include "quack.h"

#define HEIGHT 1000

struct node {
    int array[HEIGHT];
    int top;
};


//function: create and initialize a quack
//argv: void
//retrun: return an initialized Quack
Quack createQuack(void) {
    Quack qs; //define a Quack qs
    qs = (Quack) malloc(sizeof(struct node));
    if (qs == NULL) {
        fprintf (stderr, "createQuack: no memory, aborting\n");
        exit(1);
    }
    qs->top = -1;
    return qs;
}

//function: push an integer onto a quack
//argv: an integer and an initialized Quack
//retrun: void
void push(int data, Quack qs) {
    if (qs == NULL) {
        fprintf (stderr, "push: quack not initialized");
        exit(1);
    }
    if (qs->top >= HEIGHT - 1) {
        fprintf (stderr, "push: quack overflow\n");
        exit(1);
    } else {
        ++qs->top;
        qs->array[qs->top] = data;
    }
    return;

}

void qush(int data, Quack qs) {
    if (qs == NULL) {
        fprintf (stderr, "qush: quack not initialized");
        exit(1);
    }
    if (qs->top == HEIGHT - 1) {
        fprintf (stderr, "qush: quack overflow\n");
        exit(1);
    } 
    ++qs->top;     
    int i;
    for (i = qs->top; i>0; i--) { //move each element up 1
        qs->array[i] = qs->array[i-1];
    }
    qs->array[0] = data; //place the new data in the bottom
    return;
}

//function: pop the top element from the quack
//argv: Quack
//retrun: return the top element
int pop(Quack qs) {
    int retval = 0;
    if (qs == NULL) {
        fprintf (stderr, "pop: quack not initialized\n");
    }
    if (isEmptyQuack(qs)) {
       fprintf (stderr, "pop: quack underflow\n");
    } else {
       retval = qs->array[qs->top];
       --qs->top;
    }
    return retval;
}

//function: find whether the Quack is empty
//argv: Quack
//retrun: return 1 is Quack is empty, else 0
int isEmptyQuack(Quack qs) {
    int empty = 0;
    if (qs == NULL) {
        fprintf (stderr, "isEmptyQuack: quack not initialized\n");
    } else {
        empty = qs->top < 0;
    }
    return empty;
}

//function: make the quack empty
//argv: Quack
//retrun: void
void makeEmptyQuack(Quack qs) {
    if (qs == NULL) {
        fprintf (stderr, "makeEmptyQuack: quack not initialized\n");
    } else {
        while (!isEmptyQuack(qs)) {
            pop(qs);
        }
    }
    return;
}

//function: print the contents of quack, from top to the bottom
//argv: Quack
//retrun: void
void printQuack(Quack qs) {
    if (qs == NULL) {
        fprintf (stderr, "printQuack: quack not initialized\n");
    } else {
        printf ("Quack: ");
        if (qs->top < 0) {
            printf ("<< >>\n");
        } else {
            int i;
            printf ("<<%d",qs->array[qs->top]); //print the first element
            for (i = qs->top - 1; i >= 0; --i) {
                printf(", %d", qs->array[i]);
            }
            printf (">>\n");
        }
    }
    return;
}
