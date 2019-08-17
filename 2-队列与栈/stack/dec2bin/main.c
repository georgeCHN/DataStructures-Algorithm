#include <stdio.h>
#include "include/dec2bin.h"

int main() {
    int n=0;
    while(n!=-1){
        printf("input a positive num(-1 to quit):\n");
        scanf("%d",&n);
        transform(n,10,2);

    }
    return 0;
}