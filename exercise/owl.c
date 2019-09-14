//owl.c (word ladders)
/*author: Yinghong Zhong(z5233608)
  date: 31/07/2019
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool differByOne(char *a, char *b);

/*conditions: 1)only one different letter between two words; 2) adding or removing one letter
  compare their strlen and then compare each letter in the same index of two words
  if satisfy one of those conditions, return true; else return false
*/
bool differByOne(char *a, char *b) {
    int diff = 0;
    int a_len = strlen(a);
    int b_len = strlen(b);
    if ((a_len - b_len) == 0) { //check if they satisfy the first condition
        while (*a != '\0') {
            if (*a != *b) {
                diff++;
            }
            if (diff > 1) {
                return false;
            }
            a++;
            b++;
        }
    } else {
        char *long_word,*short_word;
        long_word = a;
        short_word = b;
        if ((a_len - b_len) < 0) {
            long_word = b;
            short_word = a;
        }
        while (*short_word != '\0') {
            if (*short_word == *long_word) {
                short_word++;
                long_word++;
            } else {
                diff++;
                long_word++;
            }
            if (diff > 1) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    bool n = differByOne("ban", "boat");
    if(n) {
        printf("true");
    } else {
        printf ("false");
    }
    return 0;
}
