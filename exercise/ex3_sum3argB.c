//sum3argB.c
//Yinghong Zhong
//01/07/2019
//use the stdlib function atoi() instead of sscanf(). 

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if (argc != 4 ) {
        fprintf (stderr, "please enter 3 string.\n");
        exit(1);
    } else {
        fprintf (stdout, "%d\n", atoi(argv[1]) + atoi(argv[2]) + atoi(argv[3]));
    }
    
    return 0;
}

// atoi() does no error detection: it simply returns 0 if its argument is non-integer.
// This means that the command './sum3argB.c 1 z 3' will output 4