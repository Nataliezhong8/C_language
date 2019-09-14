#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc == 2) { 
	int nth = 0;
	if (sscanf(argv[1],"%d",&nth) == 1 && (nth > 0) && (nth <= 100)) {
	    char *word = (char*)malloc(sizeof(char) * 101);
	    if (scanf("%s", word) == 1) {
			int len = strlen(word);
		if (len >= nth) {
		    for (int i = nth-1; i < len; i = i+nth) {
			printf("%c",*(word+i));
		    }
		}
	    }
	}
    }
    return 0;
}
