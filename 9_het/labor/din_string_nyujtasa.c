#include <stdio.h>
#include "debugmalloc.h"
#include <math.h>
#include <string.h>

char *masolat(char *sztring){
    char *cel = (char*)malloc((strlen(sztring)+1)*sizeof(char));
    if(cel != NULL)strcpy(cel,sztring);
    return cel;
}
// újrafoglaljuk a forrás területét, mivel a realloc magától
// átmásolja azt eredetiről az új területre a szöveget így már csak
// mellé kell fűzni az új szöveget, majd visszadni annak címét

char *hozzafuz(char *forras, char *sztring){
    char *cel = (char*)realloc(forras, ((strlen(forras)+strlen(sztring))+1)*sizeof(char));
    strcat(cel,sztring);
    return cel;
}

int main(){
    char *x = masolat("alma");
    x = hozzafuz(x, "fa");
    printf("%s\n",x);
    free(x);
}
