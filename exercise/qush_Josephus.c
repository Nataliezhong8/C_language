/* Josephus.c: use a queue to simulate a ring of n 
people, and eliminate every mth person until there is 
just a single person remaining
*/

#include <stdio.h>
#include <stdlib.h>
#include "quack.h"


int main(int argc, char *argv[]) {
    Quack q = NULL;

    int n, m;
    if ((argc != 3) || (sscanf(argv[1],"%d", &n) != 1) ||
        (sscanf(argv[2], "%d", &m) != 1)) {
            fprintf (stderr, "Usage: %s total eliminate\n", argv[0]);
            exit(1);
        }
    
    q = createQuack(); //create a quack
    int i;
    for (i = 1; i <= n; i++) { //create a queue with 1 to n numbers
        qush(i, q);
    }
    printQuack(q);
    int person = 0;
    while (!isEmptyQuack(q)) {
        for (i = 0; i < m-1; i++) { //skip m-1 people
            qush(pop(q), q);  //move persons before m from top to the bottom 
        }
        person = pop(q);
        if (!isEmptyQuack(q)) {
            printf ("Byebye %d\n", person); //elinimate him
        }
    }
    printf ("%d is the only person left\n", person);
    
    return 0;
}

