#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int tomb[10];

    for (int i = 0; i < 10; i += 1)
        tomb[i] = i * 10; //A tomb (0-9) első tíz elemét feltölti 10-esével, az első elem 0, 10, 20 .. 10.elem 90 lesz

    int i = 0;
    while (true) { //Átírva addig megy amíg a igaz a feltétel vagyis a tömb 10. eleme után memóriaszemétet ír ki, de ez így hibás lesz, mert először egy változót kéne létrehozni, aminek bool értéket adni és amíg while(valtozo) vagyis igaz, addig menne. De ehhez egy if is kell ami false ra állítja a ciklust, hogy ne a végtelenségig menjen.
        printf("%d. elem: %d\n", i, tomb[i]); //Kiírja a tömb elemeit 0.indextől, azonban i+1-gyel kéne kiírni hogy ne 0.tól kezdjünk
        i += 1;
    }

    return 0;
}
