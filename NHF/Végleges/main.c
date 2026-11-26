#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include "debugmalloc.h"
#include "Fermat_teszt.h"
#include "Miller_Rabin_teszt.h"


typedef struct ListaElem { // Adatstruktúra létrehozása a láncolt listához
    uint64_t adat;              // 'adat' tárolja az adott elem értékét, a 'kov' mutat a következõ elemre
    struct ListaElem* kov;
} ListaElem;

ListaElem* listaepites(ListaElem* eleje, uint64_t szam){ // Beszúrásos lista felépítés
    ListaElem* ujszam = (ListaElem*)malloc(sizeof(ListaElem));
    if(!ujszam)return eleje;
    ujszam->adat = szam;
    ujszam->kov = NULL;
    if(eleje == NULL)return ujszam; // Ha üres lista, akkor az új adat lesz a lista elsõ eleme
    ListaElem* mozgo = eleje;
    while(mozgo->kov != NULL)mozgo = mozgo->kov; // Végig iterálva megkeressük a legutolsó elemet és beszúrjuk utána az új elemet
    mozgo->kov = ujszam;
    return eleje; // visszatérünk a lista elsõ elemével.
}

ListaElem* bekeres(ListaElem* eleje){ // Bekérjük az adatokat és közben felépítjük velük a láncolt listát, majd visszatérve a lista elsõ elemével.
    system("cls");
    uint64_t adat = 0;
    int db = 0;
    char sor[64];
    bool sikeres = false;
    printf("---Almenu---\n\n");
    printf("Add meg a szamokat (-1 ha nincs tobb)\n");
    while(!sikeres){
        printf("%d. szam: ", db+1);
        if(scanf("%63s", sor) != 1){
            printf("Hiba: Rossz erteket adtal meg!\n\n");
            while (getchar() != '\n');
        }
        else if(strcmp(sor, "-1") == 0){
            sikeres = true;
            return eleje;
        }
        else if(sor[0] == '-' || sscanf(sor, "%llu", &adat) != 1){ // Hibakezelés
            printf("Hiba: Rossz erteket adtal meg!\n\n");
        }
        else{
            db++;
            eleje = listaepites(eleje, adat); // listaépítés
        }
    }
    printf("\n");
    return eleje;
}

bool fajlnev_ellenorzes(char *fajlnev) { // Ellenõrizzük, hogy a megadott fájlnév megfelel-e a követelményeknek
    int i = 0;
    while (fajlnev[i] != '\0' && fajlnev[i] != '.') { // Végig iterálunk a '.' - ig karakterenként
        char k = fajlnev[i];
        bool megengedett = (k == 95 || (k >= 48 && k <= 57) || (k >= 65 && k <= 90) || (k >= 97 && k <= 122)); // a megengedett karakterek ASCII kódként
        if (!megengedett) {
            return false;
        }
        i++;
    }
    if (fajlnev[i] == '\0' || i == 0)return false;
    if (strstr(fajlnev, ".txt") == NULL)return false; // Ellenõrizzük, hogy '.txt' -e a fájl kiterjesztése
    return true;
}

void fajlnev_beker(char* fajlnev){ // Fájlnév bekérése
    system("cls");
    printf("---Almenu---\n\n");
    printf("Add meg a fajl nevet ekezetek nelkul es a fajlkiterjesztest (.txt)\n\n");
    scanf("%s",fajlnev);
    while(!fajlnev_ellenorzes(fajlnev)){ // Addig kérünk be, amíg nem kapunk olyan fájlnevet, ami megfelel a követelményeknek
        printf("Hiba: Rossz fajlnevet vagy kiterjesztest adtal meg!\n"); // Hibakezelés
        scanf("%s",fajlnev);
        printf("\n");
    }
}

ListaElem* fajl_beolvasas(ListaElem* eleje, char* fajlnev, bool* hiba){ // Fájlból beolvasva felépítjük a láncolt listát, visszatérve a lista elsõ elemével.
    *hiba = false;
    FILE *f = fopen(fajlnev,"r");
    if(!f){
        *hiba = true;
        return NULL;
    }
    uint64_t szam;
    while(fscanf(f,"%llu",&szam) == 1){
        eleje = listaepites(eleje, szam); // Listaépítés
    }
    if(!feof(f) || ferror(f)){
        *hiba = true;
    }
    fclose(f);
    return eleje;
}

void eredmenyek(ListaElem* eleje, int teszt, FILE* f) { // Prímteszt, statisztika elvégzése, ha fájlból olvastunk, akkor fájlbaírunk és kiírunk, ha helybõl olvastunk, akkor csak kiírunk
    clock_t kezdet = clock(); // A futási idõ számításához
    int db = 0, sorszam = 0; // Statisztikához a változók
    uint64_t minimum = 0, maximum = 0;
    bool elso_talalat = true;
    for (ListaElem* mozgo = eleje; mozgo != NULL; mozgo = mozgo->kov) {
        bool prim_e = (teszt == 1) ? Fermat_teszt(mozgo->adat,10) : Miller_Rabin_teszt(mozgo->adat,10); // Prímteszt, minden számot 10x ellenõrzünk (ez változtatható).
        sorszam++;
        if (prim_e) {
            db++;
            fprintf(f, "A(z) %d. szam valoszinuleg prim(%llu)\n",sorszam, mozgo->adat);
            if (elso_talalat) {
                minimum = maximum = mozgo->adat;
                elso_talalat = false;
            } else {
                if (mozgo->adat < minimum) minimum = mozgo->adat;
                if (mozgo->adat > maximum) maximum = mozgo->adat;
            }
        } else {
            fprintf(f, "A(z) %d. szam valoszinuleg nem prim(%llu)\n",sorszam, mozgo->adat);
        }
    }
    clock_t veg = clock();
    double futasi_ido = (double)(veg - kezdet) / CLOCKS_PER_SEC; // Futási idõ végérték
    char *algoritmus = (teszt == 1) ? "Fermat-teszt" : "Miller-Rabin-teszt";
    fprintf(f, "A hasznalt algoritmus: %s\n", algoritmus);
    fprintf(f, "Statisztikak\nTalalt primszamok: %d db\n", db);
    if (db > 0) {
        fprintf(f, "Legkisebb primszam: %llu\nLegnagyobb primszam: %llu\n", minimum, maximum);
    } else {
        fprintf(f, "Legkisebb primszam: Nincs talalat\nLegnagyobb primszam: Nincs talalat\n");
    }
    fprintf(f, "Futasi ido: %.3f s\n", futasi_ido);
}

void fajlba_iras(ListaElem* eleje, char *fajlnev, int teszt){ // Megnyítjuk az új fájlt, amibe írni fogunk, majd az eredmények függvény használatával
    if (eleje == NULL) return;                                // fájlbaírunk, ha ez lefutott, bezárjuk a fájlt.
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

void lista_kiir(ListaElem* eleje, int teszt){ // Kiírjuk a láncolt listát az eredmények függvény használatával
    eredmenyek(eleje, teszt, stdout); // stdout -> konzolra írunk
}

void fomenu_kiir(void){ // kiíró függvény a fõmenühöz
    printf("|---------Fomenu---------|\n");
    printf("| 1. Fermat-teszt        |\n");
    printf("| 2. Miller-Rabin-teszt  |\n");
    printf("| 3. Kilepes             |\n");
    printf("|------------------------|\n\n");
}

void masodlagos_kiir(void){ // kiíró függvény a másodlagos menühöz
    system("cls");
    printf("|------Masodlagos menu------|\n");
    printf("|   1. Sajat szamok         |\n");
    printf("|   2. Fajlbeolvasas        |\n");
    printf("|   3. Kilepes              |\n");
    printf("|---------------------------|\n\n");
}

void felszabadit(ListaElem* eleje){ // Lista felszabadítása
    ListaElem* mozgo = eleje;
    while(mozgo != NULL) {
        ListaElem* kov = mozgo->kov;
        free(mozgo);
        mozgo = kov;
    }
}

void kilepes(ListaElem* eleje){ // Kilépés függvény, amivel leáll a program.
    felszabadit(eleje);
    system("cls");
    printf("Program vege.\n");
    exit(0);
}

int menu_beker(ListaElem* eleje){ // Bekérés függvény a menühöz
    int valasztas = 0;
    int eredmeny = scanf("%d",&valasztas);
    while(eredmeny != 1 || ((valasztas < 1 || valasztas > 3) && valasztas != -1)){ // Hibakezelés, addig kérünk be amíg nem felel meg a követelményeknek.
        printf("Hiba: A szamnak pozitiv egesznek kell lennie, probald ujra!\n");
        while (getchar() != '\n'); // Kivesszük a bufferbõl az entert, hogy ne legyen végtelen ciklus.
        eredmeny = scanf("%d",&valasztas);
    }
    while (getchar() != '\n');
    if(valasztas == -1){
        kilepes(eleje);
    }
    return valasztas;
}


int main(){
    ListaElem* eleje = NULL;
    int valasztas = 0;
    while(valasztas != 3){
        system("cls");
        fomenu_kiir();
        valasztas = menu_beker(eleje);
        if(valasztas == 3)kilepes(eleje);
        int fomenu_valasztas = valasztas;
        masodlagos_kiir();
        valasztas = menu_beker(eleje);
        if(valasztas == 3)kilepes(eleje);
        int masodlagos_menu_valasztas = valasztas;
        if(masodlagos_menu_valasztas == 1){
            eleje = bekeres(eleje);
            lista_kiir(eleje,fomenu_valasztas);
        }
        else{
            char fajlnev[100];
            bool hiba = false;
            fajlnev_beker(fajlnev);
            eleje = fajl_beolvasas(eleje,fajlnev,&hiba);
            if(hiba){
                printf("Hiba: Hibas adat vagy olvasasi hiba tortent a fajl beolvasasakor!\n");
                felszabadit(eleje);
                return 0;
            }
            if(eleje == NULL){
                printf("A fajl ures, nem tartalmazott szamokat.\n");
            }
            else{
                fajlba_iras(eleje, fajlnev,fomenu_valasztas);
                lista_kiir(eleje,fomenu_valasztas);
            }
        }
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        char Valasztas[3];
        printf("Vissza a menube: Enter | Kilepes: -1\n");
        fgets(Valasztas,sizeof(Valasztas),stdin);
        Valasztas[strcspn(Valasztas, "\n")] = '\0';
        if(strcmp(Valasztas,"-1") == 0){
            system("cls");
            printf("Program vege.\n");
            felszabadit(eleje);
            return 0;
        }
        felszabadit(eleje);
        eleje = NULL;
    }
}
