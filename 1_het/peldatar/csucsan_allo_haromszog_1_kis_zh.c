#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Csucsan allo haromszog\n\n");
    printf("Add meg az n erteket\n\n");
    printf("n: ");
    int n;
    int szam = 1;
    scanf("%d",&n);
    printf("\n");
    for(int i=1;i<n;i++){
        szam = szam+2;
    }
    for(int i=1;i<=n;i++){
        for(int y=1;y<i;y++)
            printf(" ");
        for(int z=1;z<=szam;z++)
            printf("o");
        szam = szam - 2;
        printf("\n");
    }
    return 0;
}
