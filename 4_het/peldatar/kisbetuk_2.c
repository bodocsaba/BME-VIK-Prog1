#include <stdio.h>
#include <ctype.h>

void kisbetus(char *szoveg){
    for(int i=0;szoveg[i] != '\0';++i){
        if(isupper(szoveg[i])){
           szoveg[i] = tolower(szoveg[i]);
        }
        printf("%c",szoveg[i]);
    }
}

int main(){
    char szoveg[] = "Irj C fuggvenyt, AMELY egy NULLAVAL terminalt SZTRINGBEN kicsereli AZ...";
    kisbetus(szoveg);
    return 0;
}
