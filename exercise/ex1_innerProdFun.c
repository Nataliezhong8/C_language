//innerProdFun.c
//Natalie 30/06/2019
#include <stdio.h>

float innerProduct(float a[], float b[], int n) {
    float sum = 0;
    for (int i = 0; i < n; i ++) {
        sum += a[i] * b[i];
    }

    return sum;
}

/*
int main() {
    float a[] = {1,2,3,4};
    float b[] = {2,3,4,5};
    int n = 4;
    float innerP =  innerProduct(a, b, n);
    printf ("inner product is %.2f\n", innerP);
    return 0;
}
 */