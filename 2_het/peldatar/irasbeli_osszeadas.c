#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    printf("Irasbeli osszeadas\n\n");
    int m[10] = {0};
    int k[10] = {0};

    // 1.szam szamjegyeinek bekerese/eltarolasa
    bool vanmegszam = true;
    int db_m = 0;
    printf("Add meg az 1.szam szamjegyeit\n\n");
    while(vanmegszam){
        printf("%d. szamjegy: ",db_m+1);
        int szamjegy = 0;
        scanf("%d",&szamjegy);
        printf("\n");
        if(szamjegy == -1){
            vanmegszam = false;
        }
        else if(szamjegy == 0 && db_m == 0){
            printf("Hiba, az elso szamjegy nem lehet nulla\n\n");
        }
        else if(szamjegy > 9 || szamjegy < -1){
            printf("Hiba, tul nagy vagy kicsi szamjegyet adtal meg (0-9)\n\n");
        }
        else{
            m[db_m] = szamjegy;
            db_m++;
        }
    }

    // 2.szam szamjegyeinek bekerese/eltarolasa
    vanmegszam = true;
    int db_k = 0;
    printf("Add meg a 2.szam szamjegyeit\n\n");
    while(vanmegszam){
        printf("%d. szamjegy: ",db_k+1);
        int szamjegy = 0;
        scanf("%d",&szamjegy);
        printf("\n");
        if(szamjegy == -1){
            vanmegszam = false;
        }
        else if(szamjegy == 0 && db_k == 0){
            printf("Hiba, az elso szamjegy nem lehet nulla\n");
        }
        else if(szamjegy > 9 || szamjegy < -1){
            printf("Hiba, tul nagy vagy kicsi szamjegyet adtal meg (0-9)\n\n");
        }
        else{
            k[db_k] = szamjegy;
            db_k++;
        }
    }
    int temp[11] = {0};
    int x = 0;
    int i = db_m-1;
    int y = db_k-1;
    int atvitel = 0;
    while(i >= 0 || y >= 0 || atvitel > 0){
        int osszeg = atvitel;
        if(i < 0 && y >= 0){
            osszeg += k[y];
        }
        else if(i >= 0 && y < 0){
            osszeg += m[i];
        }
        else if(i >= 0 && y >= 0){
            osszeg += m[i] + k[y];
        }
        temp[x] = osszeg % 10;
        atvitel = osszeg / 10;
        i--;
        y--;
        x++;
    }
    bool tulcsordulas = false;
    if(atvitel > 0 || x > 10){
        tulcsordulas = true;
        printf("Hiba: tulcsordulas tortent az osszeadas soran\n\n");
    }
    for(int i=0;i<10;i++){
        m[i] = 0;
    }
    if(x > 10){
        x = 10;
    }
    int cel =0;
    for(int kiiras = x-1; kiiras >= 0; kiiras--){
        if(cel < 10){
            m[cel] = temp[kiiras];
            cel++;
        }
    }
    if(!tulcsordulas){
        printf("A ket szam osszege: ");
        for(int kiiras = 0; kiiras < cel; kiiras++){
            printf("%d", m[kiiras]);
        }
    }
    return 0;
}
