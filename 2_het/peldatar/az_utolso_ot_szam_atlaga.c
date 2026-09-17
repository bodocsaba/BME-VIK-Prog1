#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    printf("Az utolso ot szam atlaga\n\n");
    double tomb[5];
    double szam = 1;
    bool vanmegszam = true;
    int i = 0;
    printf("Adj meg szamokat (0 - end)\n\n");
    while(vanmegszam){
            printf("Szam: ");
            scanf("%lf",&szam);
            printf("\n");
            if(szam == 0)
                vanmegszam = false;
            else if(i == 5 ){
                for(int y=0;y<=3;y++){
                    tomb[y] = tomb[y+1];
                }
                tomb[4] = szam;
            }
            else{
                tomb[i] = szam;
                i++;
            }
    }
    double atlag = 0;
    printf("Az utolso ot szam - ");
    for(int i=0;i<5;i++){
        printf("|%g| ",tomb[i]);
        atlag += tomb[i];
    }
    printf("atlaga: %g",atlag/5);

    return 0;
}
