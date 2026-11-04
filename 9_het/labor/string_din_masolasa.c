#include <stdio.h>
#include "debugmalloc.h"
#include <math.h>

// A megadott szövegnek memóriát foglalunk amit a strlen fv-el oldunk meg, ellenőrizzük
// mind a forrást mind a foglalást, majd ha minden sikeres akkor átmásoljuk a
// din.foglalt területre a szöveget majd visszaadjuk a címét,ezáltal a main() ben
// bármikor tudunk hivatkozni a din.foglalt területre, amit aztán felszabadítunk.
char *masolat(char *forras){
    if(forras == NULL)return NULL;
    char *cel = (char*)malloc((strlen(forras)+1)*sizeof(char));
    if(cel != NULL)strcpy(cel,forras);
    return cel;
}

int main(){
    char *str = masolat("asdadadasdas");
    if(str != NULL){
        printf("%s\n",str);
        free(str);
    }
    else printf("Hiba, nem sikerult memoriat foglalni.");
    return 0;
}
