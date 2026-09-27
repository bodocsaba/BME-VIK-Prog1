#include <stdio.h>

int main(){
    printf("Otvenhet\n\n");
    printf("szam: ");
    int szam;
    scanf("%d",&szam);
    printf("\n");
    char egyesek[9][7]={"egy","ketto","harom","negy","ot","hat","het","nyolc","kilenc"};
    char tizesek[9][10]={"tiz","husz","harminc","negyven","otven","hatvan","hetven","nyolcvan","kilencven"};
    int egyes = szam % 10;
    int tizes = szam / 10;
    if(tizes == 1 && egyes > 0) printf("tizen");
    else if(tizes == 2 && egyes > 0) printf("huszon");
    else printf("%s",tizesek[tizes-1]);
    if(egyes != 0)printf("%s",egyesek[egyes-1]);
    return 0;
}
