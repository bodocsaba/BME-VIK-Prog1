#include <stdio.h>
#include "debugmalloc.h"

typedef struct ListaElem{
    int adat;
    struct ListaElem* kov;
}ListaElem;

ListaElem* listaepites(ListaElem* eleje, int szam){
    ListaElem* ujelem = (ListaElem*)malloc(sizeof(ListaElem));
    ujelem->adat = szam;
    ujelem->kov = NULL;
    if(eleje == NULL)return ujelem;
    ListaElem* mozgo = eleje;
    while(mozgo->kov != NULL)mozgo=mozgo->kov;
    mozgo->kov = ujelem;
    return eleje;
}

ListaElem* atlancolas(ListaElem* eleje) {
    ListaElem* mozgo = eleje;
    ListaElem* elozo = NULL;
    ListaElem* kov = NULL;
    while (mozgo != NULL) {
        kov = mozgo->kov;
        mozgo->kov = elozo;
        elozo = mozgo;
        mozgo = kov;
    }
    return elozo;
}

void lista_kiir(ListaElem* eleje){
    if(eleje == NULL)return;
    ListaElem* mozgo = NULL;
    for(mozgo=eleje;mozgo != NULL;mozgo=mozgo->kov){
        printf("%d ",mozgo->adat);
    }
    printf("\n");
}

void felszabadit(ListaElem* eleje){
    ListaElem* mozgo = eleje;
    while(mozgo != NULL) {
        ListaElem* kov = mozgo->kov;
        free(mozgo);
        mozgo = kov;
    }
}

int main(){
    ListaElem* eleje = NULL;
    int szam;
    printf("Szam: ");
    while(scanf("%d",&szam) == 1 && szam != 0){
        eleje = listaepites(eleje,szam);
        printf("Szam: ");
    }
    printf("Eredeti: ");
    lista_kiir(eleje);
    printf("Forditva: ");
    eleje = atlancolas(eleje);
    lista_kiir(eleje);
    felszabadit(eleje);
    return 0;
}
