#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/* int main(int argc, char *argv[]) {
    int m;
    if (argc > 1) {
        /*for (int i = 1; i < argc; i++){
            int len = strspn(argv[i], "0123456789");
            if (len == strlen(argv[i])) {
                //printf("%d is an integer\n",m);
                printf("%s\n", argv[i]);
            } else{
                printf("incorrect\n");
            }
        } */

/*        for (int i = 1; i < argc; i++){
            if (isalnum(atoi(argv[i]))) {
                printf("| %s | is an alphabet or number \n", argv[i]);
            }
                
            else{
                printf("| %s | is  not an alphabet or number \n", argv[i]);
            }
        }
    }
    return 0;
    
}
*/
/*
int main() {
    int m = atoi("m");

    int n = 97;
    if (isalnum(m)) {
                printf("| %c | is an alphabet or number \n", m);
            }
                
            else{
                printf("| %c | is  not an alphabet or number \n", m);
            }
    if (isalnum(n)) {
                printf("| %c | is an alphabet or number \n", n);
            }
                
            else{
                printf("| %c | is  not an alphabet or number \n",n);
            }
    return 0;
    
}*/

int main(){
    char *n;
    n = (char*)malloc(10);
    free(n);
    n = NULL;
    int num;
    scanf("%d",&num);
    int ve[2];
    for (int i = 0; i < num; i++) {
        scanf("%d", &ve[i]);
    }
    for (int i = 0; i < num; i++) {
        printf("%d\n", ve[i]);
    }
    return 0;
}