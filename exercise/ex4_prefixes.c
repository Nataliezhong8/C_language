// prefixes.c
// print all the prefixes of a command-line arg, including itself.

#include <stdio.h>

int main(int argc, char *argv[]) {
    char *start, *end;
    if (argc == 2) {
        start = argv[1];
        end = argv[1];
        while (*end != '\0') { //find the last address of the word
            end ++;
        }
        while (start != end) {
            printf ("%s\n", start);
            end--;
            *end = '\0';
        }
    }
    return 0;

}