#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    printf("Ulohelyek\n\n");
    int ulohely[195] = {0}; // 1 szabad, 0 foglalt
    bool vanmeg = true;
    int szam = 0;
    int szokoz_db = 51;
    printf("Melyik helyet szeretned lefoglalni(szek szama)?\n");
    printf("Ha megsem szeretnel -1\n\n");
    while(vanmeg){
        printf("Szabad helyek O - szabad, X - foglalt\n\n");
        printf("%*s|-------|\n",szokoz_db,"");
        printf("%*s|Szinpad|\n",szokoz_db,"");
        printf("%*s|-------|\n\n",szokoz_db,"");
        for(int i=0;i<=12;i++){
            printf("%2d.sor ",i+1);
            for(int y=13*i;y<13*(i+1);y++){
                if(ulohely[y] == 0){
                    printf("|%4d-O ",y+1);
                }
                else if(ulohely[y] == 1){
                    printf("|%4d-X ",y+1);
                }
            }
            printf("|\n");
        }
        printf("\n");
        printf("Foglalas: ");
        scanf("%d",&szam);
        printf("\n\n");
        if(szam == -1){
            vanmeg = false;
        }
        else if(ulohely[szam-1] == 1){
            printf("Ez a hely mar foglalt, valassz masikat\n\n");
        }
        else{
            ulohely[szam-1] = 1;
        }
    }
    return 0;
}
