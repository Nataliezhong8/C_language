//sumdig.c
//yinghong zhong 
//1. treat command-line args as strings
//2.sums all the digits(0...9) that appear in all its command-line args

#include <stdio.h>
#include <stdlib.h>

/* int main(int argc, char * argv[]) {
    if (argc > 1) {
        int sum = 0;
        for (int i = 1; i < argc; i++ ) { 
            char *arg = argv[i];
            while (*arg != '\0') {
                int val = *arg - '0';
                if (val > 0 && val < 10) {
                    sum += val;
                }
                arg++;
            }
        }
        printf("%d\n", sum);
    }
    return 0;
    
}*/

int main(int argc, char *argv[]) {
    if (argc > 1) { //if no args, do nothing
        int sum = 0;
        for (int i = 1; i < argc; i++) {
            char *n = argv[i];
            while (*n != '\0') {
                int val = *n - '0';
                if (val >= 0 && val <= 9) {
                    sum += val;
                }
                n++;
            }
        }
        printf("%d\n", sum);
    }
    return 0;

}