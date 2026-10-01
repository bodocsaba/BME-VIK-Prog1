#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>

int main(){
    printf("Szamkitalalo\n\n");
    srand(time(0));
    int random = rand()%1001;
    bool nemtalalt = false;
    while(!nemtalalt){
        int tipp;
        printf("Tippelj: ");
        scanf("%d",&tipp);
        printf("\n");
        if(tipp == random){
            printf("Kitalaltad a szamot, gratulalok!\n");
            nemtalalt = true;
        }
        else if(tipp < random)
            printf("Nem talalt, a tipped kisebb, mint a szam.\n");
        else
            printf("Nem talalt, a tipped nagyobb, mint a szam.\n");
    }
    return 0;
}
