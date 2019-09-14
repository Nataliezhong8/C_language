#include <stdio.h>

int main() {
    int nums[12] = {5,3,6,2,7,4};
    printf ("nums[0]: %p\n", nums);
    printf ("nums+1: %p\n",nums+1);
    printf ("nums+2: %p\n",nums+2);
    printf ("nums+3: %p\n",nums+3);
    printf ("nums+4: %p\n",nums+4);
    return 0 ;
}