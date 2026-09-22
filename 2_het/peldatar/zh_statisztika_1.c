#include <stdio.h>

int main(){
    printf("Zh statisztika I.\n\n");
    int tomb[4] = {0};
    char csoport;
    int elso,masodik,harmadik;
    printf("Add meg a csoport jelet es a harom feladat pontszamait\n\n");
    scanf("%c %d %d %d",&csoport,&elso,&masodik,&harmadik);
    while(csoport != 'x' || elso != 0 || masodik != 0 || harmadik != 0){
        if(elso >=2 && masodik >= 2 && harmadik >=2 && elso+masodik+harmadik >= 12){
            tomb[csoport - 65]++;
        }
        scanf("%c %d %d %d",&csoport,&elso,&masodik,&harmadik);
    }
    printf("\n");
    for(int i=0;i<4;i++){
        printf("%c %d\n",65+i,tomb[i]);
    }
    return 0;
}
