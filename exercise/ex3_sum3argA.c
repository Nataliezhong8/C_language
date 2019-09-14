//sum3argA.c
//Yinghong Zhong
//01/07/2019

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int i, j, k;
    if (argc != 4 ) {
        fprintf (stderr, "please enter 3 string.\n");
        exit(1);
    }
    if ((sscanf(argv[1], "%d", &i) == 1) &&
       (sscanf(argv[2], "%d", &j) == 1) &&
       (sscanf(argv[3], "%d", &k) == 1)) {
           fprintf (stdout, "%d\n", i+j+k);
       } else {
           fprintf (stderr, "please enter 3 string.\n");
           exit(1);
       }
    
    return 0;
    
}