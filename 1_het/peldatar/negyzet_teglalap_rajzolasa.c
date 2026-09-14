#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Negyzet (teglalap) rajzolasa\n\n");

    //'*' - ból álló n*n - es négyzet
    int n;
    printf("n: ");scanf("%d",&n);printf("\n");
    for(int i=1;i<=n;i++){
        for(int y=1;y<=n;y++)
            printf("*");
        printf("\n");
    }
    printf("\n");

    //'*' - ból álló n*n - es keret

    for(int i=1;i<=n;i++){
        if(i==1 || i==n){
            for(int t=1;t<=n;t++)
                printf("*");
            printf("\n");
        }
        else{
            printf("*");
            for(int szokoz=1;szokoz<=n-2;szokoz++)
                printf(" ");
            printf("*");
            printf("\n");
        }
    }
    printf("\n\n\n");

    //'*' - ból álló n*n - es keret átlóval

    for(int elso_sor=1;elso_sor<=n;elso_sor++)
        printf("*");
    for(int i=1;i<=n-2;i++){
        printf("\n");
        printf("*");
        for(int y=1;y<i;y++)
            printf(" ");
        printf("*");
        for(int z=n-2;z>i;z--)
            printf(" ");
        printf("*");
    }
    printf("\n");
    for(int utolso_sor=1;utolso_sor<=n;utolso_sor++)
        printf("*");
    return 0;
}

