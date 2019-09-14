//quackLL.c: a linked-list-based implementation of a quack
#include <stdio.h>
#include <stdlib.h>
#include "quack.h"
#include <limits.h> //define the properties of different types of variables 
                    //eg. value of char, int, long, ect

#define HEAD_DATA INT_MAX // +32767 belong to limits.h


struct node {
    int data;
    struct node *next;
};


//function: create a head node
//argv: void
//retrun: return a head node
Quack createQuack(void) {
    Quack head; //define a Quack head
    head = malloc(sizeof(struct node));
    if (head == NULL) {
        fprintf (stderr, "createQuack: no memory, aborting\n");
        exit(1);
    }
    head->data = HEAD_DATA; //a dummy data, would never use
    head->next = NULL;
    return head;
}

//function: push an integer onto a quack
//argv: an integer and an initialized Quack
//retrun: void
void push(int data, Quack qs) {
    Quack newnode;
    if (qs == NULL) {
        fprintf (stderr, "push: quack not initialized");
        exit(1);
    } else {
        newnode = (Quack) malloc(sizeof(struct node));
        if (newnode == NULL) {
            fprintf (stderr, "push: no memory, aborting...\n");
            exit(1);
        }
        //insert a new node
        newnode->data = data; //assign the data
        newnode->next = qs->next; // link to 'old' linked list
        qs->next = newnode; //make newnode the head
    }
    return;

}

void qush(int data, Quack qs) {
    Quack newnode;
    Quack nextnode;
    if (qs == NULL) {
        fprintf (stderr, "qush: quack not initialized");
        exit(1);
    }
    newnode = (Quack) malloc(sizeof(struct node));
    if (newnode == NULL) {
        fprintf (stderr, "qush: no memory, aborting...\n");
        exit(1);
    }
    //insert a newnode to the bottom
    nextnode = qs;
    newnode->data = data;
    newnode->next = NULL;
    while (nextnode->next != NULL) {
        nextnode = nextnode->next;
    }
    nextnode->next = newnode;
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
       Quack topnode = qs->next; //top dummy node is always
       retval = topnode->data; // get the topnode data
       qs->next = topnode->next; //remove the head
       free(topnode);  //clean up
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
        empty = qs->next == NULL;
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
        if (qs->data != HEAD_DATA) {
            fprintf(stderr, "printQuack: linked list head corrupted\n");
        } else {
            printf ("Quack: ");
            if (qs->next == NULL) {
                printf ("<< >>\n");
            } else {
                printf ("<<"); 
                qs = qs->next;
                while (qs->next != NULL) {
                    printf ("%d, ", qs->data);
                    qs = qs->next;
                }
                printf ("%d>>\n", qs->data);
            }
        }
    }
    return;
}
