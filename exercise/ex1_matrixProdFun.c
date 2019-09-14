//matrixProdFun.c
//Natalie 30/06/2019

#include <stdio.h>

#define M 3
#define N 4
#define P 4

void matrixProduct(float a[M][N], float b[N][P], float c[M][P]) {
    for (int i = 0; i < M; i ++) {
        for (int j = 0; j < P; j ++) {
            c[i][j] = 0;
            for (int k = 0; k < N; k++){
                c[i][j] += a[i][k] * b[k][j]; 
            }
        }   
    }
    
    for (int i = 0; i < M; i ++) {
        for (int j = 0; j < P; j ++) {
            printf ("%.1f  ", c[i][j]);
        }
        printf("\n");
    }

}

/* 
int main() {
    float a[M][N] = {{1,1,1,1},{2,2,2,2},{3,3,3,3}};
    float b[N][P] = {{1,2,3,4,},{5,6,7,8},{2,3,4,5},{3,4,5,6}};
    float c[M][P] = {0};
    matrixProduct(a, b, c);
    return 0;
}
*/