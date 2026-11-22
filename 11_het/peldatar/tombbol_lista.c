#include <stdio.h>
#include "debugmalloc.h"

typedef struct Lista{
    double adat;
    struct Lista* kov;
}Lista;

void felszabadit(Lista* eleje){
    Lista* mozgo = eleje;
    while(mozgo != NULL){
        Lista* kov = mozgo->kov;
        free(mozgo);
        mozgo = kov;
    }
}

Lista* lista_letrehoz(double *tomb, int meret){
    if (tomb == NULL || meret <= 0)return NULL;
    Lista* elozo = NULL;
    Lista* eleje = NULL;
    for(int i = 0;i < meret;++i){
        Lista* uj = (Lista*)malloc(sizeof(Lista));
        if(!uj){
            felszabadit(eleje);
            return NULL;
        }
        uj->adat = tomb[i];
        uj->kov = NULL;
        if(elozo != NULL)elozo->kov = uj;
        else eleje = uj;
        elozo = uj;
    }
    return eleje;
}

void lista_kiir(Lista* eleje){
    if(!eleje)return;
    Lista* mozgo = eleje;
    while(mozgo != NULL){
        printf("%g ",mozgo->adat);
        mozgo = mozgo->kov;
    }
    printf("\n");
}

int main(){
    double tomb[5] = {1.1,2.3,4,7.56,10};
    Lista* eleje = NULL;
    eleje = lista_letrehoz(tomb,5);
    lista_kiir(eleje);
    felszabadit(eleje);
    return 0;
}
