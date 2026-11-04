#include <stdio.h>
#include "debugmalloc.h"

char *beszur(char *s1, int mettol, char *s2){
    int hossz = strlen(s1)+strlen(s2)+1;
    char *cel = (char*)malloc(hossz*sizeof(char));
    if(cel == NULL)return NULL;
    int i=0;
    while(i < mettol)cel[i++] = s1[i];
    char temp = s1[mettol];
    for(int y=0;s2[y]!='\0';++y)cel[i++] = s2[y];
    cel[i++] = temp;
    cel[i] = '\0';
    return cel;
}

int main(){
    char *str = beszur("hello!", 5, ", vilag");
    if(str != NULL)printf("%s\n",str);
    else printf("Hiba, nem sikerult memoriat foglalni.\n");
    free(str);
    return 0;
}
