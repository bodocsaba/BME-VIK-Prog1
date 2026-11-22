#include "debugmalloc.h"

typedef struct Lista{
    int adat[20];
    struct Lista* kov;
}Lista;

Lista* megforditas(Lista* eleje){
    Lista* elozo = NULL;
    Lista* mozgo = eleje;
    Lista* next = NULL;
    while(mozgo != NULL){
        next = mozgo->kov;
        mozgo->kov = elozo;
        elozo = mozgo;
        mozgo = next;
    }
    return elozo;
}

Lista* masolas(Lista* mozgo){
    Lista* eleje, *vege;
    for(eleje=vege=NULL;mozgo!= NULL;mozgo = mozgo->kov){
        Lista* uj = (Lista*)malloc(sizeof(Lista));
        *uj = *mozgo;
        uj->kov = NULL;
        if (eleje == NULL)
            eleje = vege = uj;
        else {
            vege->kov = uj;
            vege = vege->kov;
        }
    }
    return eleje;
}
