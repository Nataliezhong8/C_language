/* A stack can be used to check that opening and closing brackets:
 '(' and ')', '[' and ']', '{' and '}', are balanced in given text.
 */

#include <stdio.h>
#include <stdlib.h>
#include "quack.h"

#define OPENA '('
#define OPENB '['
#define OPENC '{'
#define CLOSEA ')'
#define CLOSEB ']'
#define CLOSEC '}'

int main() {
    char ch;
    Quack q = NULL;
    q = createQuack();
    printf ("Please enter brackets: ");
    int mismatch = 0;

    while ((ch=getchar()) != '\n' && !mismatch) {
        if (ch == OPENA || ch == OPENB || ch ==OPENC) {
            push((ch - '0'), q);
        } else if (ch == CLOSEA || ch == CLOSEB || ch ==CLOSEC) {
            if (isEmptyQuack(q)) {
                mismatch = 1; //opening bracket missing
            }  else {
                char open_bracket = pop(q) - 0 + '0';
                if (!((ch == CLOSEA && open_bracket == OPENA) ||
                (ch == CLOSEB && open_bracket == OPENB) ||
                (ch == CLOSEC && open_bracket == OPENC))) {
                   mismatch = 1;
               } 
            }
        }
    }

    if (!isEmptyQuack(q) || mismatch) {
        printf ("mismatch detected\n");
    }
    return 0;
}