//fastMax.c
//Natalie 30/06/2019
/*find 3 intergers and return the largest one.
only use assignment statements, a return statement and Boolean expressions
not permitted to use if-statements, loops (e.g. a while-statement), 
function calls or any data or control structures*/

#include <stdio.h>

#define A 16
#define B 21
#define C 35

int fastMax(int a,int b,int c) {
    int d = a * (a > b) + b * (a < b);
    return c * (c > d) + d * (c < d);
} 

int main(void) {
    int max_number = fastMax(A, B, C); 
    printf ("The largest number between %d, %d, %d is %d", A, B, C, max_number);
    return 0;
}