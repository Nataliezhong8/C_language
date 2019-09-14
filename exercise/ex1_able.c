//able.c
//Natalie 30/06/2019
/* output is all of the strings containing 'a', 'b', 'e', 'l', and we should
print them in alphabetical order.*/

#include <stdio.h>

#define LEN 4

int main() {
    int i, j, k, l;
    char string[] = {'a', 'b', 'e', 'l'};
    int count = 0;
    for (i = 0; i < LEN; i++) {
        for (j = 0; j < LEN; j++){
            for (k = 0; k < LEN; k++) {
                for (l = 0; l < LEN; l++){
                    if (i != j && i != k && i != l && j != k && j != l 
                    && k != l) {
                        printf("%c%c%c%c\n", string[i], string[j],string[k],string[l] );
                        count ++;
                    }
                }
            }
        }
    }
    printf ("%d\n", count);
    return 0;

}