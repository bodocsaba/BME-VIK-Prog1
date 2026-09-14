#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Hazteto\n\n");
    printf("Mekkora haztetot szeretnel?\n\n");
    printf("n: ");
    int n;
    scanf("%d",&n);
    printf("\n");

    for(int i=1;i<=n;i++){
        for(int y=n;y>i;y--)
            printf(" ");
        printf("#");
        for(int z=1;z<i;z++)
            printf("  ");
        printf("#");
        printf("\n");
    }
    return 0;
}

