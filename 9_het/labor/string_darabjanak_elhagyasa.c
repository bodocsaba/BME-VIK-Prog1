#include <stdio.h>
#include <string.h>
#include "debugmalloc.h"

// beállítjuk eleje,vége változókat és hossz, majd foglalunk din.mem.területet
// és < eleje-ig atmasoljuk karakterenkent a szöveget,majd vegetol amíg nem '\0' karaktert nem kapnuk
// szintén átmásolunk, vegül pedig visszadjuk a címet.
char *reszstring(char *sztring, int eleje, int vege){
    int hossz = strlen(sztring);
    if(eleje < 0)eleje = 0;
    if(vege > hossz)vege = hossz;
    char *cel = (char*)malloc((hossz-(vege-eleje)+1)*sizeof(char));
    int i = 0;
    while(i<eleje){
        cel[i++] = sztring[i];
    }
    while(sztring[vege] != '\0'){
        cel[i++] = sztring[vege++];
    }
    cel[i] = '\0';
    return cel;
}

int main(){
    char *str = reszstring("hello, vilag",4,8);
    printf("%s\n",str);
    free(str);
    return 0;
}
