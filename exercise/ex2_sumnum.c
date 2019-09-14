// sumnum.c
// Yinghong Zhong

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int sum = 0;
    int n;
    if (argc > 1) {
        for (int i = 1; i < argc; i++ ) {
            if (sscanf(argv[i], "%d", &n) != 1) { //sscanf() 是格式化读入，scanf()是从stdin读入
                fprintf (stderr, "error: argument %s is non-numberic", argv[i]);
                return 1;
            } else {
                sum += n;
            }
        }
        fprintf (stdout,"%d\n",sum);
    } 
    return 0;
}