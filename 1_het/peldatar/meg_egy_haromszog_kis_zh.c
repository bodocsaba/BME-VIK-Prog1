#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Meg egy haromszog\n\n");
    printf("Mekkora haromszoget szeretnel?\n\n");
    printf("n: ");
    int n;
    scanf("%d",&n);
    printf("\n");

    for(int i=1;i<=n;i++){
        for(int y=1;y<i;y++)
            printf(" ");
        for(int z=n;z>=i;z--)
            printf("o");
        printf("\n");1
    }
    return 0;
}

