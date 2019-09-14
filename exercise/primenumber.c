//primenumber.c
//determine all of the prime numbers smaller than M
//Yinghong 11/07/2019

#include <stdio.h>
#include <math.h>

#define MAXNUM 1000

int isPrime(int n){
    if (n <= 3) {
        return n > 1;
    }

    if ((n %6 != 1) && (n % 6 != 5)) {
        return 0;
    } 
    for (int i = 5; i < sqrt(n)+1; i=i+6) {
        if ((n % i == 0) || (n % (i+2) == 0) ) {
            if (n != i) {
                return 0;
            }   
        }
    }
    return 1;
}

int main() {
    int Prime[MAXNUM] = {2};//initialize the first prime number
    int count = 1; 
    if (MAXNUM == 2) {
        printf("All prime number less than 2 is: 2.\n");
    } else if (MAXNUM > 2) {
        int number[MAXNUM]; //create an array to mark if the number is prime
        for (int i = 0; i < MAXNUM; i++) {
            number[i] = 1;
        }

        for (int x = 2; x <= MAXNUM; x++) {
            if (number[x-1] == 1 && isPrime(x)) {
                if (x != 2) {
                    Prime[count++] = x;
                }
                //mark down x*j which is not prime
                for (int j = 2; j*x <= MAXNUM; j++) {
                    number[j*x-1] = 0;
                }
            }
        }

    }

    //print the prime numbers
    for (int i = 0; i < count; i++) {
        printf ("%d ", Prime[i]);
    }
    return 0;
}