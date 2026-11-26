#ifndef Miller_Rabin_h
#define Miller_Rabin_h
#include <stdbool.h>
#include <stdint.h>

// Miller-Rabin prímteszt
// szam: a vizsgált szám
// visszatérési érték: true = valószínûleg prím, false = összetett
// ismetlesek: hányszor ellenőrizze a számot, hogy prím-e.

bool Miller_Rabin_teszt(uint64_t szam, int ismetlesek);

#endif
