#include <stdio.h>

void kiir(char* string,int meddig){
    for(int i=0;i<=meddig;++i)printf("%c",string[i]);
    printf("\n");
}

int rekurziv_pozicio(char* string, int i,int nyito, int zaro){
    if(string[i] == '\0')return -1;
    if(string[i] == '(')nyito++;
    else if(string[i] == ')')zaro++;
    if(nyito == zaro)return i;
    return rekurziv_pozicio(string,i+1,nyito,zaro);
}

int iterativ_pozicio(char* string){
    int nyito = 0, zaro = 0;
    for(int i=0;string[i] != '\0';++i){
        if(string[i] == '(')nyito++;
        else if(string[i] == ')')zaro++;
        if(nyito == zaro)return i;
    }
    return -1;
}

int main(){
    char string[] = "(alma,(banan),korte,(szilva),barack),mogyoro";
    int index = rekurziv_pozicio(string,0,0,0);
    int index2 = iterativ_pozicio(string);
    if(index != -1){
        kiir(string,index);
        kiir(string,index2);
    }
    else printf("Hiba, nem volt lezaro lezaro ')'.");
    return 0;
}
