//ackermann.c
//yinghong zhong
//11/07/2019

#include <stdio.h>
#include <stdlib.h>

int ackermann(int m, int n){
	if (m == 0 && n >= 0) {
	    return n+1;
	} else if(m > 0 && n == 0) {
	    return ackermann(m-1, 1);
	} else if(m > 0 && n > 0) {
	    return ackermann(m-1, ackermann(m, n-1));
	}
	return 0;
}

int main(int argc, char *argv[]) {
	int m,n;
	if (argc != 3 || sscanf(argv[1],"%d", &m) != 1 
	    || sscanf(argv[2],"%d", &n) != 1 ) {
	    fprintf (stderr, "Usage: ./%s m n\n", argv[0]);
	    exit(1);
	}
	if (m < 0 || n < 0) {
	    fprintf (stderr, "Ackermanns function is not defined for negative integers\n");
	    exit(1);
	} 
	int ack = ackermann(m,n);
	printf("Ackermann(%d, %d) = %d\n", m, n, ack);
	return 0;
}
