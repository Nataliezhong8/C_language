//quack.h: an interface definition for a stack/ queue

#ifndef _QUACK_H_
#define _QUACK_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct node *Quack;

//function: create and initialize a quack
//argv: void
//retrun: return an initialized Quack
Quack createQuack(void);

//function: push an integer onto a quack
//argv: an integer and an initialized Quack
//retrun: void
void push(int, Quack);

void qush(int, Quack);

//function: pop the top element from the quack
//argv: Quack
//retrun: return the top element
int pop(Quack);

//function: find whether the Quack is empty
//argv: Quack
//retrun: return 1 is Quack is empty, else 0
int isEmptyQuack(Quack);

//function: make the quack empty
//argv: Quack
//retrun: void
void makeEmptyQuack(Quack);

//function: print the contents of quack, from top to the bottom
//argv: Quack
//retrun: void
void printQuack(Quack);

#endif