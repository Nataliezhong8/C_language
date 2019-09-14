//fivedigits.c
//Natalie 30/06/2019

#include <stdio.h>
#define MIN 20008
#define MAX 24999

int main() {
    int n;
    int a,b,c,d,e;
    for (n = MIN; n < MAX; n++) {
        e = n % 10;
        d = n / 10 % 10;
        c = n / 100 % 10;
        b = n / 1000 % 10;
        a = n / 10000 %10;
        if (4 * n == a + 10 * b + 100 * c + 1000 * d + 10000 * e) {
            printf ("This 5-digit number is: %d\n", n);
        }
    }
    

    return 0;

}