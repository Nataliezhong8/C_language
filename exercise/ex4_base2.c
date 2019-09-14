//base2.c
/* A stack can be used to convert a positive 
number n base 10 (i.e. a decimal number) to a number base m*/

#include <stdio.h>
#include <stdlib.h>
#include "quack.h"

#define BASE 2

int main(int argc, char *argv[]) {
    int n;
    Quack q = NULL;
    if (argc != 2 || (sscanf(argv[1], "%d", &n) != 1) ||
        n < 0) {
        fprintf (stderr, "Usage: ./%s number\n", argv[0]);
        return 1;
    } else {
        if (n == 0) {
            printf("%d\n",n);
        } else {
            q = createQuack();
            while (n > 0) {
                push((n % BASE), q);
                n = n / BASE;
            }
            
            //print the numbers
            while (!isEmptyQuack(q)) {
                printf ("%d", pop(q));
            }
            putchar('\n');
            return 0;
        }

    }

}

