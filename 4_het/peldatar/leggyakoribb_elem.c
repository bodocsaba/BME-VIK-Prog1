#include <stdio.h>

int leggyakoribb_elem(int *tomb, int meret){
    int leggyakoribb = tomb[0];
    int ossz = 0;
    for(int i=0;i<meret;++i){
        int elofordulas = 1;
        for(int y=0;y<meret;++y){
            if(tomb[i] == tomb[y])elofordulas++;
        }
        if(elofordulas > ossz){
            leggyakoribb = tomb[i];
            ossz = elofordulas;
        }
    }
    return leggyakoribb;
}

int main(){
    int tomb[10] = {2,7,5,8,9,5,7,5,5,3};
    printf("Leggyakoribb elem: %d",leggyakoribb_elem(tomb,10));
    return 0;
}
