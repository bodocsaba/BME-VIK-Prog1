#include <stdio.h>
#include "debugmalloc.h"
#include <string.h>

typedef struct ListaElem{
    char* adat;
    struct ListaElem* kov;
}ListaElem;

ListaElem* listaepites(ListaElem* eleje, char* szo){
    ListaElem* ujelem = (ListaElem*)malloc(sizeof(ListaElem));
    ujelem->adat = (char*)malloc((strlen(szo) + 1) * sizeof(char));
    strcpy(ujelem->adat, szo);
    ujelem->kov = NULL;
    if(eleje == NULL)return ujelem;
    ListaElem* mozgo = eleje;
    while(mozgo->kov != NULL)mozgo=mozgo->kov;
    mozgo->kov = ujelem;
    return eleje;
}

ListaElem* listaelem_torles(ListaElem* eleje) {
    ListaElem* mozgo = eleje;
    ListaElem* elozo = NULL;
    while (mozgo != NULL) {
        ListaElem* kov = mozgo->kov;
        if(strlen(mozgo->adat) == 4){
            if (elozo == NULL)eleje = kov;
            else elozo->kov = kov;
            free(mozgo->adat);
            free(mozgo);
            mozgo = kov;
        }
        else{
            elozo = mozgo;
            mozgo = kov;
        }
    }
    return eleje;
}

void lista_kiir(ListaElem* eleje){
    if(eleje == NULL)return;
    ListaElem* mozgo = NULL;
    for(mozgo=eleje;mozgo != NULL;mozgo=mozgo->kov){
        printf("%s ",mozgo->adat);
    }
    printf("\n");
}

void felszabadit(ListaElem* eleje){
    ListaElem* mozgo = eleje;
    while(mozgo != NULL) {
        ListaElem* kov = mozgo->kov;
        free(mozgo->adat);
        free(mozgo);
        mozgo = kov;
    }
}

int main(){
    ListaElem* eleje = NULL;
    char szo[100];
    printf("Szo: ");
    while(scanf("%s",szo) == 1 && strcmp(szo,"-1")){
        eleje = listaepites(eleje,szo);
        printf("Szo: ");
    }
    eleje = listaelem_torles(eleje);
    lista_kiir(eleje);
    felszabadit(eleje);
    return 0;
}
