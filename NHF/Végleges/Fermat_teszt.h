#ifndef Fermat_teszt_h
#define Fermat_teszt_h
#include <stdbool.h>
#include <stdint.h>

// Fermat prímteszt
// szam: a vizsgált szám
// visszatérési érték: true = valószínûleg prím, false = összetett
// ismetlesek: hányszor ellenőrizze a számot, hogy prím-e.

bool Fermat_teszt(uint64_t szam, int ismetlesek);

#endif
