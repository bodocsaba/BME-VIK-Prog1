#include <stdio.h>
#include "debugmalloc.h"
#include <string.h>

typedef struct Szalloda{
    int szoba;
    char vendeg[50+1];
    struct Szalloda* kov;
}Szalloda;

Szalloda* listaepites(Szalloda* eleje, int szobaszam ,char* nev){
    Szalloda* uj = (Szalloda*)malloc(sizeof(Szalloda));
    if(!uj)return eleje;
    uj->szoba = szobaszam;
    strncpy(uj->vendeg,nev,50);
    uj->vendeg[50] = '\0';
    uj->kov = NULL;
    if(!eleje)return uj;
    Szalloda* mozgo = eleje;
    while(mozgo->kov != NULL)mozgo = mozgo->kov;
    mozgo->kov = uj;
    return eleje;
}

Szalloda* fajlbeolvasas(Szalloda* eleje, char* fajlnev){
    FILE* f = fopen(fajlnev, "r");
    if(!f)return eleje;
    int szobaszam;
    char nev[50+1];
    while(fscanf(f, "%d %50[^\n]",&szobaszam,nev) == 2){
        eleje = listaepites(eleje,szobaszam,nev);
    }
    fclose(f);
    return eleje;
}

int* hany_vendeg(Szalloda* eleje){
    if(!eleje)return NULL;
    int* tomb = (int*)calloc(8,sizeof(int));
    if(!tomb)return NULL;
    Szalloda* mozgo = eleje;
    while(mozgo != NULL){
        int emelet = mozgo->szoba / 100;
        tomb[emelet]++;
        mozgo = mozgo->kov;
    }
    return tomb;
}

int legzsufoltabb(int *tomb, int meret){
    int maximum = 0;
    for(int i = 1;i < meret;++i){
        if(tomb[i] > tomb[maximum])maximum = i;
    }
    return maximum;
}

void felszabaditas(Szalloda* eleje){
    Szalloda* mozgo = eleje;
    while(mozgo != NULL){
        Szalloda* kov = mozgo->kov;
        free(mozgo);
        mozgo = kov;
    }
}

int megszallt_e(Szalloda* eleje, char* nev){
    Szalloda* mozgo = eleje;
    while(mozgo != NULL){
        if(strcmp(mozgo->vendeg,nev) == 0)return mozgo->szoba/100;
        mozgo = mozgo->kov;
    }
    return -1;
}

int main(){
    Szalloda* eleje = NULL;
    eleje = fajlbeolvasas(eleje,"foglalasok.txt");
    int *tomb = NULL;
    tomb = hany_vendeg(eleje);
    int maximum = legzsufoltabb(tomb,8);
    char nev[50+1];
    printf("Nev: ");
    scanf("%50[^\n]",nev);
    int talalt = megszallt_e(eleje,nev);
    if(talalt != -1){
        if(talalt == maximum)printf("Az illeto megszallt a szallodaban és a legzsufoltabb(%d) emeleten van a szobaja.\n",maximum);
        else printf("Az illeto megszallt a szallodaban.\n");
    }
    else printf("Az illeto nem szallt meg a szallodaban.\n");
    free(tomb);
    felszabaditas(eleje);
    return 0;
}
