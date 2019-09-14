
//count+.c
//Yinghong Zhong
//01/07/2019

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int end= 0;
    if (argc != 2 || (sscanf(argv[1], "%d", &end) != 1)) {
        fprintf (stderr, "Usage: ./ %s number\n", argv[0]);
        exit (1);
    } 

    if (end < 0 ) {
        fprintf (stderr, "Usage: ./ %s number\n", argv[0]);
    } else {
        fprintf (stdout, "0");
    }
    if (end > 0) {
        for (int i = 1; i <= end; i++) {
            fprintf (stdout, ",%d",i);
        }
    }
    printf ("\n"); 
    return 0;

}