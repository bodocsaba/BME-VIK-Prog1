#include "debugmalloc.h"

typedef struct Lista{
    int adat;
    struct Lista* kov;
}Lista;

Lista* listaepites(void){
    Lista* eleje = NULL;
    int tomb[11] = {1,1,5,7,4,4,1,5,5,5,6};
    for(int i=0;i<11;++i){
        Lista* uj = (Lista*)malloc(sizeof(Lista));
        if(!uj)return eleje;
        uj->adat = tomb[i];
        uj->kov = NULL;
        if(eleje != NULL){
            Lista* mozgo = eleje;
            while(mozgo->kov != NULL)mozgo = mozgo->kov;
            mozgo->kov = uj;
        }
        else eleje = uj;
    }
    return eleje;
}

Lista* lista_modosit(Lista* eleje){
    if(!eleje)return eleje;
    Lista* mozgo = eleje;
    while(mozgo->kov != NULL){
        if(mozgo->adat == mozgo->kov->adat){
            Lista* kov = mozgo->kov->kov;
            free(mozgo->kov);
            mozgo->kov = kov;
        }
        else{
            mozgo = mozgo->kov;
        }
    }
    return eleje;
}

void lista_kiir(Lista* eleje){
    if(!eleje)return;
    Lista* mozgo = eleje;
    while(mozgo != NULL){
        printf("%d ",mozgo->adat);
        mozgo = mozgo->kov;
    }
    printf("\n");
}

void felszabadit(Lista* eleje){
    Lista* mozgo = eleje;
    while(mozgo != NULL){
        Lista* kov = mozgo->kov;
        free(mozgo);
        mozgo = kov;
    }
}

int main(){
    Lista *eleje = listaepites();
    lista_kiir(eleje);
    eleje = lista_modosit(eleje);
    lista_kiir(eleje);
    felszabadit(eleje);
    return 0;
}
