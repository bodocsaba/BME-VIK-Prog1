#include <stdio.h>
#include <string.h>
#include "debugmalloc.h"

// beállítjuk eleje és vége változókat, majd foglalunk din.mem.területet
// és eleje-vegeig atmasoljuk karakterenkent a szöveget, majd pedig lezárjuk azt
// és visszadjuk a címet.
char *reszstring(char *sztring, int eleje, int vege){
    if(eleje < 0)eleje = 0;
    if(vege > strlen(sztring))vege = strlen(sztring);
    char *cel = (char*)malloc(((vege-eleje)+1)*sizeof(char));
    int i = 0;
    while(eleje < vege){
        cel[i++] = sztring[eleje++];
    }
    cel[i] = '\0';
    return cel;
}

int main(){
    char *str = reszstring("hello, vilag",3,9);
    printf("%s\n",str);
    free(str);
    return 0;
}
