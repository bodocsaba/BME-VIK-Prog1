#include <stdio.h>

int *elofordulas(int *tomb, int meret){
    for(int i=0;i<meret;++i){
        int elofordulas = 1;
        for(int y=i+1;y<meret;++y)if(tomb[i] == tomb[y])elofordulas++;
        if(elofordulas >= 2)return &tomb[i];
    }
    return NULL;
}

int main(){
    int tomb[10] = {10,20,30,50,60,90,70,80,90,70};
    int *index = elofordulas(tomb,10);
    if(index != NULL)printf("Tombelem cime: %p",(void*)index);
    else printf("Nem volt ilyen szam.");
    return 0;
}
