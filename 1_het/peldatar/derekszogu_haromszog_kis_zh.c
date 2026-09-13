#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Derekszogu haromszog\n\n");
    printf("Add meg az n erteket\n\n");
    printf("n: ");
    int n;
    scanf("%d",&n);
    printf("\n");
    int behuzas = n;
    int szokoz = 1;
    for(int i=1;i<=n;i++){
        for(int y=1;y<behuzas;y++)
            printf(" ");
        behuzas--;
        printf("/");
        if(i>1)
            for(int z=1;z<szokoz;z++)
                printf(" ");
        szokoz++;
        printf("|\n");
    }
    for(int i = 1;i<=n;i++)
        printf("-");
    printf("+");
    return 0;
}
