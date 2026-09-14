#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Paralelogramma\n\n");
    printf("Add meg a szelesseget es magassagot\n\n");
    printf("szelesseg x: ");
    int x;
    scanf("%d",&x);
    printf("\n");
    printf("magassag y: ");
    int y;
    scanf("%d",&y);
    printf("\n");

    for(int i=1;i<=y;i++){
        for(int z=i;z<y;z++)
            printf(" ");
        for(int k=1;k<=x;k++)
            printf("o");
        printf("\n");
    }
    return 0;
}

