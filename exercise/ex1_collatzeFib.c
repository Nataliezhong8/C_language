//collatzeFib.c
//Natalie 30/06/2019
/*Write a C program that calls the function in Part a. 
with the first 10 Fibonacci numbers. The program should print
 the Fibonacci number followed by its corresponding series. */

#include <stdio.h>

#define MAX 10

void number_output(int n) {
    while (n > 1) {
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }
        printf ("%d ", n);
    }
    printf("\n");

}

int main(void) {
    int pre = 1;
    int cur = 1;
    printf("Fib[1] = 1:\n");
    printf("Fib[2] = 1:\n");
    for (int i = 3; i <= MAX; i++) {
        int fib = pre + cur;
        printf ("Fib[%d] = %d: ", i, fib);
        number_output(fib);
        pre = cur;
        cur = fib;
    }
    return 0;

}