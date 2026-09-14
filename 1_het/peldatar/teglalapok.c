#include <stdio.h>
#include <stdlib.h>


int main(){
    printf("Teglalapok\n\n");
    int m,n,a,b,k;
    printf("m: ");scanf("%d",&m);printf("\n");
    printf("n: ");scanf("%d",&n);printf("\n");
    printf("a: ");scanf("%d",&a);printf("\n");
    printf("b: ");scanf("%d",&b);printf("\n");
    printf("k: ");scanf("%d",&k);printf("\n");

    for(int i=1;i<=n;i++){
        for(int y=1;y<=b;y++){
            printf("\n");
            for(int z=1;z<=m;z++){
                for(int t=1;t<=a;t++)
                    printf("o");
                for(int sortores=1;sortores<=k;sortores++)
                    printf(" ");
            }
        }
        for(int szokoz=1;szokoz<=k;szokoz++)
                printf("\n");
    }
    return 0;
}

