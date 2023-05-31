#include <stdio.h>

int main(void){
    int n = 4;
    int *n_ptr = &n;
    printf("n = %d, n_ptr = %d", n,*n_ptr);
    return 0;
}