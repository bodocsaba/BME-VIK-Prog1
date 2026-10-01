#include <stdio.h>
#include <string.h>

void trim(char *forras, char *cel){
    int eleje = 0;
    for(int i=0;forras[i] ==' ';++i)eleje++;
    int vege = strlen(forras)-1;
    while(forras[vege] == ' ')vege--;
    int index = 0;
    for(int i=eleje;i<=vege;++i){
        cel[index++] = forras[i]; 
    }
    cel[index] = '\0';
}

int main(){
    char szoveg[] = "  hello, mizu?  ";
    char cel[30];
    trim(szoveg,cel);
    printf("%s",cel);
    return 0;
}
