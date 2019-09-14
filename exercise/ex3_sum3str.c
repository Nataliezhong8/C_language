//sum3str.c
//Yinghong Zhong
//01/07/2019

#include <stdio.h>

int main() {
    char *r = "1";
    char *s = "23"; 
    char *t = "456";

    int rr, ss, tt;
    if ((sscanf(r, "%d",&rr) == 1)
       && (sscanf(s, "%d",&ss) == 1)
       && (sscanf(t, "%d%d%d",&tt) == 1)) {
           printf ("%d\n", rr+ss+tt);
    }
    return 0;

}