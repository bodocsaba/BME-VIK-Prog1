#include "Miller_Rabin_teszt.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include "debugmalloc.h"

uint64_t miller_mod_osszead(uint64_t a, uint64_t b, uint64_t modulo) { // segédfüggvény a miller_szorzo fv-hez a moduláris szorzáshoz
    a %= modulo;
    b %= modulo;
    if (a >= modulo - b) {
        return a - (modulo - b);
    }
    return a + b;
}

uint64_t miller_szorzo(uint64_t a, uint64_t b, uint64_t modulo) { // Ez kivédi a 64 bites túlcsordulást a szorzáskor
    uint64_t eredmeny = 0;
    a %= modulo;
    b %= modulo;
    while (b > 0) {
        if (b % 2 == 1) {
            eredmeny = miller_mod_osszead(eredmeny, a, modulo);
        }
        a = miller_mod_osszead(a, a, modulo);
        b /= 2;
    }
    return eredmeny;
}

uint64_t miller_hatvanyozas(uint64_t alap, uint64_t kitevo, uint64_t modulo) { // gyors moduláris hatványozással kiszámoljuk az (a^n-1) mod n maradékot.
    uint64_t eredmeny = 1;                                                     // Segédfüggvényként a szorzo-t felhasználjuk
    alap %= modulo;
    while (kitevo > 0) {
        if (kitevo % 2 == 1) {
            eredmeny = miller_szorzo(eredmeny, alap, modulo);
        }
        alap = miller_szorzo(alap, alap, modulo);
        kitevo /= 2;
    }
    return eredmeny;
}

// Egyetlen 'a' tanúra ellenõrzi a Miller-Rabin feltételt
bool tanu_teszt(uint64_t d, uint64_t szam, uint64_t a) {
    uint64_t x = miller_hatvanyozas(a, d, szam);
    if (x == 1 || x == szam - 1) {
        return true;
    }
    while (d != szam - 1) {
        x = miller_szorzo(x, x, szam);
        d *= 2;
        if (x == 1) return false;       // összetett
        if (x == szam - 1) return true; // Átment a próbán
    }
    return false;
}

bool Miller_Rabin_teszt(uint64_t szam, int ismetlesek) {
    if (szam <= 1 || szam == 4) return false; // Ha a szám kisebb vagy egyenlõ, mint 1 vagy 4, akkor biztosan nem prímek visszatérünk hamissal.
    if (szam == 2 || szam == 3) return true;  // Ha a szám 2 vagy 3, akkor biztosan prímek visszatérünk igazzal.
    if (szam % 2 == 0) return false; // Páros számok (2-n kívül) nem prímek
    // Felbontjuk szam - 1-et d * 2^r alakra, ahol d páratlan
    uint64_t d = szam - 1;
    while (d % 2 == 0){
        d /= 2;
    }
    for (int i = 0; i < ismetlesek; i++) {
        uint64_t a = 2 + (uint64_t)rand() % (szam - 3);
        if (!tanu_teszt(d, szam, a)) {
            return false; // Biztosan összetett
        }
    }
    return true; // Valószínûleg prím
}
