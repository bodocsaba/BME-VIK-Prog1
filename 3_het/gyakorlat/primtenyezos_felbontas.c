#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Primtenyezos felbontas\n\n");
    int szam;
    printf("szam: ");
    scanf("%d",&szam);
    printf("\n");
    int oszto = 2;
    while(szam > 1){
        if(szam % oszto == 0){
            printf("%3d|%d\n",szam,oszto);
            szam /= oszto;
        }
        else{
            oszto++;
        }
    }
    printf("%3d|1",1);
    return 0;
}
