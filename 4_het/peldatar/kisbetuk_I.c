#include <stdio.h>
#include <ctype.h>

int numLower(char *szoveg){
    int db = 0;
    for(int i=0;szoveg[i] != '\0';++i)
        if(islower(szoveg[i]))db++;
    return db;
}

int main(){
    char szoveg[] = "Keszits fuggvenyt, AMI megkap EGY stringre MUTATO pointert.";
    printf("%d db kisbetu volt.", numLower(szoveg));
    return 0;
}
