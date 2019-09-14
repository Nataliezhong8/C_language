//recount+.c
//Yinghong Zhong
//01/07/2019

#include <stdio.h>
#include <stdlib.h>

void print_nb (int begin,int end) {
    if (begin == end) {
        fprintf (stdout, "%d", begin);
    } else {
        fprintf (stdout, "%d,", begin);
        begin++;
        print_nb(begin, end);
    }
    return;
}

int main (int argc, char* argv[]) {
    int end = 0;
    if (argc != 2 || (sscanf (argv[1], "%d", &end) != 1)) {
        fprintf (stderr, "Usage: ./%s number", argv[0]);
        exit(1);
    }
    if (end < 0) {
        fprintf (stderr, "Usage: ./%s number", argv[0]);
        exit(1);
    }
    int n = 0;
    print_nb(n, end);
    printf ("\n");
}