#include <stdio.h>
#include <stdlib.h>

int main(){
    int tomb[24] = {0};
    int ora,perc,osszeg;
    char tipus;
    printf("Add meg az orat, percet, birsag fajtajat es osszeget (0 0 x 0) a vege\n\n");
    scanf("%d %d %c %d", &ora, &perc, &tipus,&osszeg);
    while(ora != 0 || perc != 0 || tipus != 'x' || osszeg != 0){
        if(tipus == 'h' && ora >= 0 && ora<=23){
            tomb[ora] += osszeg;
        }
        else if(tipus == 'c' && ora >= 0 && ora<=23){
            tomb[ora] += osszeg*0.8;
        }
        scanf("%d %d %c %d", &ora, &perc, &tipus,&osszeg);
    }
    printf("\n");
    for(int i=0;i<24;i++){
        if(tomb[i] > 0){
            printf("%2d:00-%2d:59, %dFt\n",i,i,tomb[i]);
        }
    }
    return 0;
}
