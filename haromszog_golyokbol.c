#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Haromszog golyokbol\n\n");
    int n;
    printf("Mekkora haromszoget szeretnel?\n");
    printf("n: ");
    scanf("%d",&n);
    printf("\n");
    int golyokszama = 1;
    for(int i=1;i<=n;i++){
        for(int y=n;y>=i;y--){
            printf(" ");
        }
        for(int z=1;z<=golyokszama;z++){
            printf("o");
        }
        golyokszama += 2;
        printf("\n");
    }
    return 0;
}
