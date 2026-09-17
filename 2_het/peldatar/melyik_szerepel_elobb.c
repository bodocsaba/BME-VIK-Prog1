#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main(){
    printf("Melyik szerepel elobb\n\n");
    printf("Adj meg ketto szamot es a program eldonti szerepel-e a tombben\n\n");
    printf("Az elso szam: ");
    int szam;
    if(scanf("%d",&szam) != 1){
        printf("Hiba, nem egesz szamot adtal meg.");
        return 0;
    }
    printf("\n");
    printf("A masodik szam: ");
    int szam2;
    if(scanf("%d",&szam2) != 1){
        printf("Hiba, nem egesz szamot adtal meg.");
        return 0;
    }
    printf("\n");

    srand(time(0));
    bool bennevane_szam = false;
    bool bennevane_szam2 = false;
    int index_szam = 0;
    int index_szam2 = 0;
    int m = 100; // Bármekkora pozitív egész szám lehet
    int tomb[m];
    for(int i=0;i<m;i++){
        tomb[i] = rand();
        if(szam == tomb[i]){
            bennevane_szam = true;
            index_szam = i;
        }
        else if(szam2 == tomb[i]){
            bennevane_szam2 = true;
            index_szam2 = i;
        }
    }
    if(bennevane_szam && bennevane_szam2 && index_szam != index_szam2){
        printf("A %d es %d szamok benne vannak a tombben\n",szam,szam2);
        if(index_szam < index_szam2)
                printf("A %d szam szerepel elobb.", szam);
        else if(index_szam2 < index_szam)
                printf("A %d szam szerepel elobb.", szam2);
    }
    else
        printf("A ket szam nincs benne a tombben.");

    return 0;
}
