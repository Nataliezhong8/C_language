#include <stdio.h>
#include <stdlib.h>


int main(){
    int a = 10;
    char *c = malloc(sizeof(char) * a);
    c = "hello";
    printf("%s\n", c);
    return 0;
}