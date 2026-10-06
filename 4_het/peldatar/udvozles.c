#include <stdio.h>

int main(){
    printf("Hogy hivnak?\n");
    printf("neved: ");
    char nev[100];
    fgets(nev,sizeof(nev),stdin);
    printf("Udvozollek %s",nev);
    return 0;
}
