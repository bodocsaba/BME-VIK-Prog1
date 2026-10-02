#include <stdio.h>

int egyedi_elemek_szama(int *tomb, int meret){
    int ossz = 0;
    for(int i=0;i<meret;++i){
        int elofordulas = 1;
        for(int y=0;y<meret;++y){
            if(tomb[i] == tomb[y])elofordulas++;
        }
        if(elofordulas < 3)ossz++;
    }
    return ossz;
}

int main(){
    int tomb[10] = {2,7,5,8,9,5,7,5,5,3};
    printf("Egyedi elemek szama: %d",egyedi_elemek_szama(tomb,10));
    return 0;
}
