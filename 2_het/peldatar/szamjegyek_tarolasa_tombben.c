#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    printf("Add meg a szamjegyeket, -1 ha nincs tobb\n\n");
    int m[10];
    int db = 0;
    for(int i=0;i<10;i++){
        printf("%d szamjegy: ",i+1);
        int szamjegy = 0;
        scanf("%d", &szamjegy);
        if(szamjegy == -1)
            break;
        else
            m[i] = szamjegy;
        printf("\n");
        db++;
    }
    int osszeg = 0;
    for(int i=0;i<db;i++){
        int szorzo = 1;
        for(int y=db-1;y>=i+1;y--){
            szorzo *=10;
        }
        osszeg += m[i] * szorzo;
    }

    printf("\n");
    printf("Az abrazolt x szam osszege: %d\n",osszeg);
    if(m[db-1] == 9){
            printf("Tulcsordulas tortent az (x+1) szamnal\n");
            printf("Az abrazolt (x+1) szam osszege: %d",osszeg+1);
    }
    else
        printf("Az abrazolt szam (x+1) osszege: %d",osszeg+1);
    return 0;
}
