#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("n*n-es tablazat\n\n");
    int n;
    int szamlalo = 1;
    printf("Add meg mekkora n*n-es tablazatot szeretnel\n\n");
    printf("n: ");
    scanf("%d",&n);
    printf("\n");
    for(int i=1;i<=n;i++){
        printf("|");
        for(int i=1;i<=4*n+1;i++)
            printf("-");
        printf("|");
        printf("\n");
        printf("|");
        printf(" ");
        for(int y=1;y<=n;y++){
            printf("|%d|",szamlalo);
            if(szamlalo < 10)
                printf(" ");
            szamlalo = szamlalo+1;
        }
        printf("|");
        printf("\n");
    }
    printf("|");
    for(int i=1;i<=4*n+1;i++)
            printf("-");
    printf("|");
    return 0;
}

