#include <stdio.h>
#include <stdlib.h>
#include "debugmalloc.h"

typedef struct BiFa {
    int ertek;
    struct BiFa *bal, *jobb;
} BiFa;

BiFa *beszur(BiFa *gyoker, int ertek) {
    if (gyoker == NULL) {
        BiFa *uj = (BiFa*) malloc(sizeof(BiFa));
        uj->ertek = ertek;
        uj->bal = uj->jobb = NULL;
        return uj;
    }
    if (ertek < gyoker->ertek) {        /* balra szur */
        gyoker->bal = beszur(gyoker->bal, ertek);
    }
    else if (ertek > gyoker->ertek) {   /* jobbra szur */
        gyoker->jobb = beszur(gyoker->jobb, ertek);
    }
    else {
        /* mar benne van */
    }
    return gyoker;
}

void inorder_kiir(BiFa* gyoker){
    if (gyoker == NULL)return;
    inorder_kiir(gyoker->bal);
    printf("%d ", gyoker->ertek);
    inorder_kiir(gyoker->jobb);
}

void fa_torles(BiFa* gyoker){
    if(gyoker == NULL)return;
    fa_torles(gyoker->bal);
    fa_torles(gyoker->jobb);
    free(gyoker);
}

int elemek_szama(BiFa* gyoker){
    if(gyoker == NULL)return 0;
    return elemek_szama(gyoker->bal) + elemek_szama(gyoker->jobb) + 1;
}

int elemek_sum(BiFa* gyoker){
    if(gyoker == NULL)return 0;
    return elemek_sum(gyoker->bal) + elemek_sum(gyoker->jobb) + gyoker->ertek;
}

int* kereses(BiFa* gyoker, int szam){
    if(gyoker == NULL)return NULL;
    if(gyoker->ertek == szam)return &gyoker->ertek;
    if(szam < gyoker->ertek)return kereses(gyoker->bal,szam);
    else return kereses(gyoker->jobb,szam);
}

void negalas(BiFa* gyoker){
    if (gyoker == NULL)return;
    negalas(gyoker->bal);
    gyoker->ertek *= -1;
    negalas(gyoker->jobb);
}

int* negalt_kereses(BiFa* gyoker, int szam){
    if(gyoker == NULL)return NULL;
    if(gyoker->ertek == szam)return &gyoker->ertek;
    if(szam < gyoker->ertek)return negalt_kereses(gyoker->jobb,szam);
    else return negalt_kereses(gyoker->bal,szam);
}

void tukrozes(BiFa* gyoker){
    if(gyoker == NULL)return;
    tukrozes(gyoker->bal);
    tukrozes(gyoker->jobb);
    BiFa* temp = gyoker->bal;
    gyoker->bal = gyoker->jobb;
    gyoker->jobb = temp;
}

int main(void) {
    int minta[] = {15, 96, 34, 12, 14, 56, 21, 11, 10, 9, 78, 43, 0};
    BiFa *gyoker = NULL;
    for (int i = 0; minta[i] > 0; i++)
        gyoker = beszur(gyoker, minta[i]);
    /* Ide tedd be a kipróbálandó függvények hívásait! */
    inorder_kiir(gyoker);
    printf("\n");
    int db = elemek_szama(gyoker);
    printf("Elemek szama: %d\n",db);
    int sum = elemek_sum(gyoker);
    printf("Elemek osszege: %d\n",sum);
    int* ptr = kereses(gyoker,43);
    ptr != NULL ? printf("A keresett szam benne van.\n") : printf("A keresett szam nincs benne.\n");
    negalas(gyoker);
    inorder_kiir(gyoker);
    printf("\n");
    ptr = negalt_kereses(gyoker,-43);
    ptr != NULL ? printf("A keresett szam benne van.\n") : printf("A keresett szam nincs benne.\n");
    tukrozes(gyoker);
    inorder_kiir(gyoker);
    fa_torles(gyoker);
    printf("\n");
    return 0;
}
