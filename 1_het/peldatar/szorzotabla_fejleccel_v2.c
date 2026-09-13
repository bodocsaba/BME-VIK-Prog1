#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Szorzotabla fejleccel(v2)\n\n");
    int n;
    printf("Add meg hanyszor hanyas szorzotablat szeretnel\n\n");
    printf("n: ");
    scanf("%d",&n);
    printf("\n");
    printf("  |");
    for(int i=1;i<=n;i++){
        printf("%4d",i);
    }
    printf("\n");
    printf("--+");
    for(int i=1;i<=n;i++){
        printf("----");
    }
    printf("\n");
    for(int i=1;i<=n;i++){
        printf("%2d|",i);
        for(int y=1;y<=n;y++){
            printf("%4d",y*i);
        }
        printf("\n");
    }
    return 0;
}
