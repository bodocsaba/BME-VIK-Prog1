#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "debugmalloc.h"
#include "Fermat_teszt.h"
#include "Miller_Rabin_teszt.h"


typedef struct ListaElem {
    int adat;
    struct ListaElem* kov;
} ListaElem;

ListaElem* listaepites(ListaElem* eleje, int szam){
    ListaElem* ujszam = (ListaElem*)malloc(sizeof(ListaElem));
    ujszam->adat = szam;
    ujszam->kov = NULL;
    if(eleje == NULL)return ujszam;
    ListaElem* mozgo = eleje;
    while(mozgo->kov != NULL)mozgo = mozgo->kov;
    mozgo->kov = ujszam;
    return eleje;
}

ListaElem* bekeres(ListaElem* eleje){
    system("cls");
    int adat = 0;
    int db = 0;
    printf("---Almenu---\n\n");
    printf("Add meg a szamokat (-1 ha nincs tobb)\n");
    while(adat != -1){
        printf("%d. szam: ", db+1);
        int eredmeny = scanf("%d", &adat);
        if(eredmeny != 1 || adat < -1){
            printf("Hiba: Rossz erteket adtal meg!\n\n");
            while (getchar() != '\n');
        }
        else if(adat != -1){
            db++;
            eleje = listaepites(eleje, adat);
        }
    }
    printf("\n");
    return eleje;
}

bool fajlnev_ellenorzes(char *fajlnev) {
    int i = 0;
    while (fajlnev[i] != '\0' && fajlnev[i] != '.') {
        char k = fajlnev[i];
        bool megengedett = (k == 95 || (k >= 48 && k <= 57) || (k >= 65 && k <= 90) || (k >= 97 && k <= 122));
        if (!megengedett) {
            return false;
        }
        i++;
    }
    if (fajlnev[i] == '\0' || i == 0)return false;
    if (strstr(fajlnev, ".txt") == NULL)return false;
    return true;
}

void fajlnev_beker(char* fajlnev){
    system("cls");
    printf("---Almenu---\n\n");
    printf("Add meg a fajl nevet ekezetek nelkul es a fajlkiterjesztest (.txt)\n\n");
    scanf("%s",fajlnev);
    while(!fajlnev_ellenorzes(fajlnev)){
        printf("Hiba: Rossz fajlnevet vagy kiterjesztest adtal meg!\n");
        scanf("%s",fajlnev);
        printf("\n");
    }
}

ListaElem* fajl_beolvasas(ListaElem* eleje, char* fajlnev){
    FILE *f = fopen(fajlnev,"r");
    if(!f)return NULL;
    int szam;
    while(fscanf(f,"%d",&szam) == 1){
        eleje = listaepites(eleje, szam);
    }
    fclose(f);
    return eleje;
}

void eredmenyek(ListaElem* eleje, int teszt, FILE* f) {
    if (eleje == NULL) return;
    clock_t kezdet = clock();
    int db = 0, minimum = 0, maximum = 0;
    bool elso_talalat = true;
    for (ListaElem* mozgo = eleje; mozgo != NULL; mozgo = mozgo->kov) {
        bool prim_e = (teszt == 1) ? Fermat_teszt(mozgo->adat,10) : Miller_Rabin_teszt(mozgo->adat,10);
        db++;
        if (prim_e) {
            fprintf(f, "A(z) %d. szam valoszinuleg prim(%d)\n",db, mozgo->adat);
            if (elso_talalat) {
                minimum = maximum = mozgo->adat;
                elso_talalat = false;
            } else {
                if (mozgo->adat < minimum) minimum = mozgo->adat;
                if (mozgo->adat > maximum) maximum = mozgo->adat;
            }
        } else {
            fprintf(f, "A(z) %d. szam valoszinuleg nem prim(%d)\n",db, mozgo->adat);
        }
    }
    clock_t veg = clock();
    double futasi_ido = (double)(veg - kezdet) / CLOCKS_PER_SEC;
    char *algoritmus = (teszt == 1) ? "Fermat-teszt" : "Miller-Rabin-teszt";
    fprintf(f, "A hasznalt algoritmus: %s\n", algoritmus);
    fprintf(f, "Statisztikak\nTalalt primszamok: %d db\n", db);
    if (db > 0) {
        fprintf(f, "Legkisebb primszam: %d\nLegnagyobb primszam: %d\n", minimum, maximum);
    } else {
        fprintf(f, "Legkisebb primszam: Nincs talalat\nLegnagyobb primszam: Nincs talalat\n");
    }
    fprintf(f, "Futasi ido: %.3f s\n", futasi_ido);
}

void fajlba_iras(ListaElem* eleje, char *fajlnev, int teszt){
    if (eleje == NULL) return;
    char ujfajl[100];
    int meddig = strcspn(fajlnev, ".");
    strncpy(ujfajl, fajlnev, meddig);
    ujfajl[meddig] = '\0';
    strcat(ujfajl, "_eredmeny.txt");
    FILE *f = fopen(ujfajl, "w");
    if (f == NULL) {
        printf("Hiba: Sikertelen fajl megnyitas\n");
        return;
    }
    eredmenyek(eleje, teszt, f);
    fclose(f);
}

void lista_kiir(ListaElem* eleje, int teszt){
    eredmenyek(eleje, teszt, stdout);
}

void fomenu_kiir(void){
    printf("|---------Fomenu---------|\n");
    printf("| 1. Fermat-teszt        |\n");
    printf("| 2. Miller-Rabin-teszt  |\n");
    printf("| 3. Kilepes             |\n");
    printf("|------------------------|\n\n");
}

void masodlagos_kiir(void){
    system("cls");
    printf("|------Masodlagos menu------|\n");
    printf("|   1. Sajat szamok         |\n");
    printf("|   2. Fajlbeolvasas        |\n");
    printf("|   3. Kilepes              |\n");
    printf("|---------------------------|\n\n");
}

void kilepes(){
    system("cls");
    printf("Program vege.");
    exit(0);
}

int menu_beker(void){
    int valasztas = 0;
    int eredmeny = scanf("%d",&valasztas);
    while(eredmeny != 1 || ((valasztas < 1 || valasztas > 3) && valasztas != -1)){
        printf("Hiba: A szam nem lehet negativ vagy nem egesz, probald ujra!\n");
        while (getchar() != '\n');
        eredmeny = scanf("%d",&valasztas);
    }
    while (getchar() != '\n');
    if(valasztas == -1){
        kilepes();
    }
    return valasztas;
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
    int valasztas = 0;
    while(valasztas != 3){
        system("cls");
        fomenu_kiir();
        valasztas = menu_beker();
        if(valasztas == 3)kilepes();
        int fomenu_valasztas = valasztas;
        masodlagos_kiir();
        valasztas = menu_beker();
        if(valasztas == 3)kilepes();
        int masodlagos_menu_valasztas = valasztas;
        if(masodlagos_menu_valasztas == 1){
            eleje = bekeres(eleje);
            lista_kiir(eleje,fomenu_valasztas);
        }
        else{
            char fajlnev[100];
            fajlnev_beker(fajlnev);
            eleje = fajl_beolvasas(eleje,fajlnev);
            if(eleje == NULL){
                printf("Hiba, nem sikerult a fajlbeolvasas, program vege.");
                felszabadit(eleje);
                return 0;
            }
            fajlba_iras(eleje, fajlnev,fomenu_valasztas);
            lista_kiir(eleje,fomenu_valasztas);
        }
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        char Valasztas[3];
        printf("Vissza a menube: Enter | Kilepes: -1\n");
        fgets(Valasztas,sizeof(Valasztas),stdin);
        if(strcmp(Valasztas,"-1") == 0){
            system("cls");
            printf("Program vege.");
            felszabadit(eleje);
            return 0;
        }
        felszabadit(eleje);
        eleje = NULL;
    }
}
