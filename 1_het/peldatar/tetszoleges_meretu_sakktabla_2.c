#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Tetszoleges meretu sakktabla 2.\n\n");
    printf("Mekkora legyen a sakktabla?\n\n");
    printf("n: ");
    int n;
    scanf("%d",&n);
    printf("\n");

    for(int i=1;i<=n;i++){
        for(int y=1;y<=2;y++){
            for(int behuzas=1;behuzas<=20;behuzas++)
                printf(" ");
            for(int z=1;z<=n;z++)
                printf("**..");
            printf("\n");
        }
        for(int y=1;y<=2;y++){
            for(int behuzas=1;behuzas<=20;behuzas++)
                printf(" ");
            for(int z=1;z<=n;z++)
                printf("..**");
            printf("\n");
        }
    }
    return 0;
}

