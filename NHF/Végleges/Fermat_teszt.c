#include "Fermat_teszt.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include "debugmalloc.h"

// A Fermat-teszt a Fermat kis tételén alapul: ha 'n' prím, akkor bármilyen 'a' számra (amely nem osztható n-nel) teljesül, hogy
// a^n-1 kongruens 1 (mod n) vagyis ha ez teljesül, akkor n valószínûleg prím.

uint64_t fermat_mod_osszead(uint64_t a, uint64_t b, uint64_t modulo) { // segédfüggvény a fermat_szorzo fv-hez a moduláris szorzáshoz
    a %= modulo;
    b %= modulo;
    if (a >= modulo - b) {
        return a - (modulo - b);
    }
    return a + b;
}

uint64_t fermat_szorzo(uint64_t a, uint64_t b, uint64_t modulo) { // Ez kivédi a 64 bites túlcsordulást a szorzáskor
    uint64_t eredmeny = 0;
    a %= modulo;
    b %= modulo;
    while (b > 0) {
        if (b % 2 == 1) {
            eredmeny = fermat_mod_osszead(eredmeny, a, modulo);
        }
        a = fermat_mod_osszead(a, a, modulo);
        b /= 2;
    }
    return eredmeny;
}

uint64_t fermat_hatvanyozas(uint64_t alap, uint64_t kitevo, uint64_t modulo){ // gyors moduláris hatványozással kiszámoljuk az (a^n-1) mod n maradékot.
    uint64_t eredmeny = 1;                                                    // Segédfüggvényként a szorzo-t felhasználjuk
    alap %= modulo;
    while (kitevo > 0) {
        if (kitevo % 2 == 1) {
            eredmeny = fermat_szorzo(eredmeny, alap, modulo);
        }
        alap = fermat_szorzo(alap, alap, modulo);
        kitevo /= 2;
    }
    return eredmeny;
}

bool Fermat_teszt(uint64_t szam, int ismetlesek){
    if(szam <= 1 || szam == 4)return false; // Ha a szám kisebb vagy egyenlõ, mint 1 vagy 4, akkor biztosan nem prímek visszatérünk hamissal.
    if(szam == 2 || szam == 3)return true;  // Ha a szám 2 vagy 3, akkor biztosan prímek visszatérünk igazzal.
    for (int i = 0;i<ismetlesek;i++){
        uint64_t a = 2 + (uint64_t)rand() % (szam - 3); // választunk 2 és n-1 közötti random 'a' számot, (uint_64 64 bit tárolásához)
        if (fermat_hatvanyozas(a, szam - 1, szam) != 1) {
            return false; // Biztosan összetett vagyis nem prím
        }
    }
    return true; // prím a szám
}
