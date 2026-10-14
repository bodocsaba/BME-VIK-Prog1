#include <stdio.h>

void sztringet_kiir_1(char *szoveg) {
    if (szoveg[0] == '\0')
        return;
    putchar(szoveg[0]);       // Itt kiírja a szoveg 0.indexének a karakterét, majd
    printf("%s", szoveg + 1); // kiírja az 1.indextõl a többit is.
}


void sztringet_kiir_2(char *szoveg) {
    if (szoveg[0] == '\0')
        return;
    putchar(szoveg[0]);           // Itt is kiírja a szoveg 0.karakterét, majd
    sztringet_kiir_2(szoveg + 1); // újra meghívva és közben léptetve a pointert
}                                 // kiírja a pointer értékét
                                  // pointer szemszögébõl még a 0.indexen vagyunk, csak el lett tolva 1-gyel, ezért írjuk ki a 0.indexet mindig

int main(void) {
    sztringet_kiir_1("alma");
    printf("\n");
    sztringet_kiir_2("alma");
    return 0;
}
