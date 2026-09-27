#include <stdio.h>
/*
int main(){
    printf("Szamkitalalo forditva\n\n");
    int szam;
    printf("Adj meg egy szamot 1 es 100 kozott majd a program megprobalja kitalalni\n");
    printf("szamod: ");
    scanf("%d",&szam);
    printf("\n");
    int tipp = 50;
    int maxtipp = 100;
    int mintipp = 0;
    while(tipp != szam){
        char valasz;
        printf("Kisebb a szam, mint %d (i vagy n)?\n",tipp);
        scanf(" %c",&valasz);
        if(valasz == 'i' || valasz == 'I'){
            maxtipp = tipp;
            tipp = maxtipp - (maxtipp-mintipp)/2;
        }
        else if(valasz == 'n' || valasz == 'N'){
            mintipp = tipp;
            tipp = mintipp + (maxtipp-mintipp)/2;
        }
        printf("\n");
    }
    printf("A gep sikeresen kitalalta a szamod --> tipp: %d es a szamod: %d",tipp,szam);
    return 0;
}
*/
