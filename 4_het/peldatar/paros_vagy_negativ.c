#include <stdio.h>
#include <stdbool.h>

int tipusok(int *tomb, int meret){ // 0 ha osszevissza, 1 ha csokkeno, 2 ha novekvo
    int paros = 2;
    int negativ = -1;
    int mindketto = 1;
    int egyiksem = 0;
    int minden_paros = true;
    int minden_negativ = true;
    for(int i=0;i<meret;++i){
        if(tomb[i]>=0) minden_negativ = false;
        if(tomb[i] % 2 != 0) minden_paros = false;
    }
    if(minden_paros && minden_negativ) return mindketto;
    else if(minden_paros && !minden_negativ) return paros;
    else if(!minden_paros && minden_negativ) return negativ;
    else return egyiksem;
}

int main(){
    int tomb[10] = {2,4,0,8,10,12,14,16,18,20};
    int tomb2[10] = {1,3,5,7,9,11,13,15,17,19};
    int tomb3[10] = {-2,-4,-6,-8,-10,-12,-14,-16,-18,-20};
    int tipus = tipusok(tomb,10);
    if(tipus == 2)printf("A tomb paros.");
    else if(tipus == -1)printf("A tomb negativ.");
    else if(tipus == 1)printf("A tomb paros es negativ.");
    else printf("Egyiksem");
    return 0;
}
