#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Ket szakasz\n\n");
    printf("Mekkora legyen a 2 szakasz?\n\n");
    printf("n: ");
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        printf("\n");
        for(int y=1;y<i;y++)
            printf(" ");
        printf("#");
        for(int z=1;z<=n-1;z++)
            printf(" ");
        printf("#");
    }
    return 0;
}

