#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Szakasz\n\n");
    printf("Milyen hosszu es hany sornyi szakaszt szeretnel?\n\n");
    printf("Hossz (m): ");
    int m;
    scanf("%d",&m);
    printf("\n");
    printf("sorok szama (n): ");
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        printf("\n");
        for(int y=1;y<i;y++)
            for(int behuzas=1;behuzas<=m;behuzas++)
                printf(" ");
        for(int z=1;z<=m;z++)
            printf("x");
    }
    return 0;
}

