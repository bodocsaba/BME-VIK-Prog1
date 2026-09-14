#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Csucsan allo haromszog_2\n\n");
    printf("Add meg az n erteket\n\n");
    printf("n: ");
    int n;
    scanf("%d",&n);
    printf("\n");

    for(int i=1;i<=n;i++){
        for(int y=n;y>i;y--)
            printf(" ");
        for(int z=1;z<=i;z++)
            printf("o");
        printf("\n");
    }
    for(int i=n;i>1;i--){
        for(int y=i-1;y<n;y++)
            printf(" ");
        for(int z=1;z<i;z++)
            printf("o");
        printf("\n");
    }
    return 0;
}

