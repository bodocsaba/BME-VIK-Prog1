#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Adott meretu negyzet rajzolasa\n\n");
    printf("Mekkora negyzetet szeretnel?\n\n");
    int n;
    printf("n: ");scanf("%d",&n);printf("\n");
    printf("+");
    for(int i=1;i<=n;i++)
        printf("-");
    printf("+\n");
    for(int i=1;i<=n;i++){
        printf("|");
        for(int y=1;y<i;y++)
            printf(" ");
        printf("\\");
        for(int t=n;t>i;t--)
            printf(" ");
        printf("|\n");
    }
    printf("+");
    for(int i=1;i<=n;i++)
        printf("-");
    printf("+");
    return 0;
}
