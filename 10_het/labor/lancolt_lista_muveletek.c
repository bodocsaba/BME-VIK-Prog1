#include <stdio.h>
#include <stdlib.h>
#include "debugmalloc.h"

typedef struct ListaElem {
    int adat;
    struct ListaElem* kov;
} ListaElem;


/* létrehoz egy listát, benne egy csomó számmal */
ListaElem* lista_letrehoz(void) {
    int szamok[] = { 8, 14, 13, 17, 1, 19, 16, 5, 3, 11, 2, // Azért vannak fordítva mert fordítva építettük fel a listát és
                     15, 9, 10, 6, 22, 4, 7, 18, 27, -1 };  // az első elem nem a 8 hanem a 27 lesz, ezért előre iterálva a 8
    ListaElem* lis = NULL;                                  // lesz az utolsó elem aminek kov NULL ra fog mutatni.

    for (int i = 0; szamok[i] != -1; ++i) {
        ListaElem* u;
        u = (ListaElem*) malloc(sizeof(ListaElem));
        u->kov = lis;
        u->adat = szamok[i];
        lis = u;
    }
    return lis;
}
// listán végighaladva a mozgo pointerrel kiírjuk az adatokat, amíg nem NULL.
void lista_kiir(ListaElem* eleje){
    ListaElem* mozgo;
    for(mozgo=eleje;mozgo != NULL;mozgo=mozgo->kov){
        printf("%d ",mozgo->adat);
    }
    printf("\n");
}
// Végighaladunk mozgo pointerrel a listán és minden egyes lépésnél növeljük a hosszt, amíg nem NULL, majd visszadjuk a hosszt.
int lista_hossza(ListaElem* eleje){
    ListaElem* mozgo;
    int hossz = 0;
    for(mozgo=eleje;mozgo!=NULL;mozgo=mozgo->kov)hossz++;
    return hossz;
}
// Végighaladva a listán felszabadítjuk az adatokat, de előtte a következő adatra mutató pointert lementjuk egy másikba és utána szabadítjuk fel.
void felszabadit(ListaElem* eleje){
    ListaElem* mozgo = eleje;
    while(mozgo != NULL) {
        ListaElem* kov = mozgo->kov;
        free(mozgo);
        mozgo = kov;
    }
}
// Lefoglalunk memóriát az új számnak, inicializáljuk, majd beállítjuk, hogy az a "volt" első számra mutasson a pointer (ujszam->kov), majd visszadjuk a pointert.
ListaElem* lista_elejere_beszur(ListaElem* eleje, int szam){
    ListaElem* ujszam = (ListaElem*)malloc(sizeof(ListaElem));
    ujszam->adat = szam;
    ujszam->kov = eleje;
    return ujszam;
}
// Lefoglalunk memóriát az új számnak, inicializáljuk, ha a lista nem üres, akkor végig iterálva amíg nem NULL megkapjuk a lista utolsó elemét, amit beállítunk, hogy az új elemre mutasson.
ListaElem* lista_vegere_beszur(ListaElem* eleje, int szam){
    ListaElem* ujszam = (ListaElem*)malloc(sizeof(ListaElem));
    ujszam->adat = szam;
    ujszam->kov = NULL;
    if(eleje == NULL)return ujszam;
    ListaElem* mozgo = eleje;
    while(mozgo->kov != NULL)mozgo = mozgo->kov;
    mozgo->kov = ujszam;
    return eleje;
}
// Végig iterálunk a listán, amíg nem NULL vagy megnem találjuk a keresett számot és visszadunk egy pointert, ha ez NULL akkor nincs benne.
ListaElem* kereses(ListaElem* eleje, int szam){
    ListaElem* mozgo = eleje;
    while(mozgo != NULL && mozgo->adat != szam){
        mozgo = mozgo->kov;
    }
    return mozgo;
}

int main(void) {
    ListaElem *eleje = lista_letrehoz();
    lista_kiir(eleje);
    printf("A lista hossza: %d\n\n",lista_hossza(eleje));
    eleje = lista_elejere_beszur(eleje, 21);
    lista_kiir(eleje);
    lista_vegere_beszur(eleje,50);
    lista_kiir(eleje);
    ListaElem* szam = kereses(eleje,180);
    if(szam != NULL)printf("A keresett szam benne van a listaban.\n");
    else printf("A keresett szam nincs benne a listaban.\n");
    felszabadit(eleje);
    return 0;
}
