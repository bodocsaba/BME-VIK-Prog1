#include <stdio.h>

void szamrendszer_kiir(int szam,int szamrendszer){
    if(szam == 0)return;
    szamrendszer_kiir(szam/szamrendszer,szamrendszer);
    if(szamrendszer == 16 && szam%szamrendszer >=10 && szam%szamrendszer <=15){
        printf("%c", szam%szamrendszer + 'A');
    }
    else printf("%d", szam%szamrendszer);
}

int main(){
    szamrendszer_kiir(19,16);
    return 0;
}
