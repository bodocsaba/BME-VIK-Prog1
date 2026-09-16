#include <stdio.h>

int main(void) {
    char betu;
    while (scanf("%c", &betu) == 1)
        printf("betu='%c', betu=%d\n", betu, betu);
    // A beírt szöveg(ek)-et betûnként kiírja és mellé az ASCII számát is
    return 0;
}
