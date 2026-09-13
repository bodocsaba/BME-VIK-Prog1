#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Szorzotabla fejleccel\n\n");
    int n;
    printf("Add meg hanyszor hanyas szorzotablat szeretnel\n\n");
    printf("n: ");
    scanf("%d",&n);
    printf("\n");
    printf("    | ");
    for(int i=1;i<=n;i++){
        if(i>9)
            printf(" %d  ",i);
        else
            printf("  %d  ",i);
    }
    printf("\n");
    printf("  --+----");
    for(int i=1;i < n;i++){
        printf("-----");
    }
    printf("\n");
    for(int i=1;i<=n;i++){
        if(i>9)
            printf("  %d| ",i);
        else
            printf("   %d| ",i);
        for(int y=1;y<=n;y++){
            if(y==1 && y*i > 9)
                printf(" %d ",y*i);
            else if((y+1)*i> 99)
                printf("  %d",y*i);
            else if((y+1)*i> 9)
                printf("  %d ",y*i);
            else
                printf("  %d  ",y*i);
        }
        printf("\n");
    }

    return 0;
}
