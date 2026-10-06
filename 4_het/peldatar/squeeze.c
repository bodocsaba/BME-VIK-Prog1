#include <stdio.h>
#include <string.h>

void squeeze(char *szoveg, char *sztring){
    int index = 0;
    for(int i=0;szoveg[i] != '\0';++i){
        if(strchr(sztring,szoveg[i]) == NULL)
            szoveg[index++] = szoveg[i];
    }
    szoveg[index] = '\0';
}

int main(){
    char szoveg[] = "megadott sztring";
    char sztring[] = "gt";
    squeeze(szoveg,sztring);
    printf("%s",szoveg);
    return 0;
}
