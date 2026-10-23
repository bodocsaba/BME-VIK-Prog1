#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct lista{
    char nev[100];
    int pontszam;
}lista;

void rendez(lista* nevek, int meret){
    for(int i=0;i<meret-1;++i){
        int minindex = i;
        for(int y=i+1;y<meret;++y){
            if(nevek[y].pontszam < nevek[minindex].pontszam)minindex = y;
        }
        lista temp = nevek[i];
        nevek[i] = nevek[minindex];
        nevek[minindex] = temp;
    }
}

void kiir(lista* nevek, int meret){
    printf("Dicsoseglista\n");
    for(int i=meret-1;i>=0;--i){
        printf("%2d. helyezett {%s,%d}\n",meret-i,nevek[i].nev,nevek[i].pontszam);
    }
    printf("\n");
}

bool felkerul_e(lista* nevek, int meret, int pszam){
    return pszam > nevek[0].pontszam;
}

int helyezes(lista* nevek, int meret, lista bejegyzes){
    if(!felkerul_e(nevek,meret,bejegyzes.pontszam))return -1;
    nevek[0] = bejegyzes;
    rendez(nevek,meret);
    for(int i=meret-1;i>=0;--i)
        if(strcmp(nevek[i].nev,bejegyzes.nev) == 0)return meret-i;
}

int main(){
    lista nevek[20] = {
        {"Kovacs Anna", 85},
        {"Nagy Peter", 92},
        {"Szabo Eszter", 78},
        {"Toth Gabor", 95},
        {"Horvath Katalin", 64},
        {"Varga Laszlo", 88},
        {"Kiss Zsofia", 91},
        {"Molnar Tamas", 72},
        {"Fekete Timea", 83},
        {"Balogh David", 79},
        {"Gulyas Martin", 90},
        {"Takacs Lili", 86},
        {"Lakatos Bence", 67},
        {"Meszaros Petra", 94},
        {"Olah Mate", 75},
        {"Simon Dorina", 81},
        {"Racz Adam", 89},
        {"Fodor Vivien", 76},
        {"Pinter Zoltan", 93},
        {"Kocsis Luca", 84}
    };
    rendez(nevek,20);
    int hanyadik = helyezes(nevek,20,(lista){"Bodo Csaba",90});
    if(hanyadik != -1){
        kiir(nevek,20);
        printf("A helyezes: %d.\n",hanyadik);
    }
    else printf("Nem kerult fel a dicsoseglistara.\n");
    return 0;
}
