#include <stdio.h>

typedef struct Datum {
    int ev, ho, nap;
}Datum;

typedef struct Versenyzo {
    char nev[31];
    Datum szuletes;
    int helyezes;
} Versenyzo;

void datum_kiir(Datum d);

void versenyzo_kiir(Versenyzo v);

int main() {
    Versenyzo versenyzok[5] = {
        { "Am Erika", {1984, 5, 6}, 1 },
        { "Break Elek", {1982, 9, 30}, 3 },
        { "Dil Emma", {1988, 8, 25}, 2 },
        { "Kasza Blanka", {1979, 6, 10}, 5 },
        { "Reset Elek", {1992, 4, 5}, 4 },
    };
    printf("%s\n",versenyzok[0].nev);
    printf("%d\n",versenyzok[2].helyezes);
    datum_kiir(versenyzok[4].szuletes);
    printf("\n");
    printf("%c\n",versenyzok[1].nev[0]); // vagy printf("%.1s",versenyzok[1].nev);
    if(versenyzok[1].helyezes <=3)printf("igen\n");
    if(versenyzok[4].helyezes < versenyzok[3].helyezes)printf("gyorsabb\n");
    if(versenyzok[1].szuletes.ev == versenyzok[2].szuletes.ev)printf("ugyanabban az evben szulettek\n");
    versenyzo_kiir(versenyzok[1]);
    printf("\n\n");
    for(int i=0;i<5;i++){
        versenyzo_kiir(versenyzok[i]);
        printf("\n");
    }
    return 0;
}

void datum_kiir(Datum d){
    printf("%d.",d.ev);
    printf("%d.",d.ho);
    printf("%d",d.nap);
}

void versenyzo_kiir(Versenyzo v){
    printf("%s, ",v.nev);
    datum_kiir(v.szuletes);
    printf(", %d ",v.helyezes);
}
