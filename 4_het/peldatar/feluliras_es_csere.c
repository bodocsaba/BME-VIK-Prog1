#include <stdio.h>

int db_csere(char *szoveg, char b1, char b2){
    int db = 0;
    for(int i=0;szoveg[i] != '\0';++i){
        if(szoveg[i] == b1){
            szoveg[i] = b2;
            db++;
        }
    }
    return db;
}

int db_csere2(char *szoveg, char b1, char b2){
    int db = 0;
    for(int i=0;szoveg[i] != '\0';++i){
        if(szoveg[i] == b1){
            szoveg[i] = b2;
            db++;
        }
        else if(szoveg[i] == b2){
            szoveg[i] = b1;
            db++;
        }
    }
    return db;
}

int main(){
    char szoveg[] = "alma";
    printf("%d db csere volt.",db_csere(szoveg,'a','e'));
    printf("%s\n\n",szoveg);
    char szoveg2[] = "feluliras";
    printf("%d db csere volt.\n",db_csere2(szoveg2,'a','e'));
    printf("%s\n",szoveg2);
    return 0;
}
