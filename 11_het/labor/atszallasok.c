#include <stdio.h>
#include <string.h>
#include "debugmalloc.h"

typedef struct Megallo{
    char adat[50+1];
    struct Megallo *kov;
}Megallo;

Megallo* listaepites(Megallo* eleje, const char* megallo){
    Megallo* uj = (Megallo*)malloc(sizeof(Megallo));
    if(uj == NULL)return eleje;
    strncpy(uj->adat,megallo,50);
    uj->adat[50] = '\0';
    uj->kov = NULL;
    if(eleje == NULL)return uj;
    Megallo* mozgo = eleje;
    while(mozgo->kov != NULL)mozgo = mozgo->kov;
    mozgo->kov = uj;
    return eleje;
}

Megallo* fajl_beolvasas(Megallo* eleje, char* fajlnev){
    FILE* f = fopen(fajlnev,"r");
    if(f == NULL)return eleje;
    char megallo[50+1];
    while(fscanf(f," %50[^\n]",megallo) == 1){
        eleje = listaepites(eleje, megallo);
    }
    fclose(f);
    return eleje;
}

char* atszallas(Megallo* m1, Megallo* m2){
    Megallo* belso = m1;
    while(belso != NULL){
        Megallo* kulso = m2;
        while(kulso != NULL){
            if(strcmp(belso->adat,kulso->adat) == 0){
                char* talalat = (char*)malloc(strlen(belso->adat)+1);
                if(talalat != NULL){
                    strcpy(talalat,belso->adat);
                    return talalat;
                }
            }
            kulso = kulso->kov;
        }
        belso = belso->kov;
    }
    return NULL;
}

void felszabadit(Megallo* eleje){
    Megallo* mozgo = eleje;
    while(mozgo != NULL){
        Megallo* kov = mozgo->kov;
        free(mozgo);
        mozgo = kov;
    }
}

int main(){
    Megallo* m2 = NULL;
    Megallo* m3 = NULL;
    m2 = fajl_beolvasas(m2,"m2.txt");
    m3 = fajl_beolvasas(m3,"m3.txt");
    char *kereses = atszallas(m2,m3);
    if(kereses != NULL)printf("%s\n",kereses);
    else printf("Nincs lehetoseg atszallni.\n");
    free(kereses);
    felszabadit(m2);
    felszabadit(m3);
    return 0;
}
