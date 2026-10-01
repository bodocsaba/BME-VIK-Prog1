#include <stdio.h>

int main(){
    printf("Primszamok 999-ig\n\n");
    int tomb[998];
    int db = 0;
    int szam;
    printf("Add meg a szamot: ");
    scanf("%d",&szam);
    printf("\n\n");
    for(int i=0;i<998;i++)tomb[i] = i+2;
    for(int i=0;i<998;i++){
        int oszto = tomb[i]*tomb[i];
        if(tomb[i] != 0){
            while(oszto < 1000){
                tomb[oszto-2] = 0;
                oszto += tomb[i];
            }
        }
        if(tomb[i] !=0){
            printf("%3d ",tomb[i]);
            db++;
            if(db % 10 == 0)printf("\n");
        }
    }
    printf("\n\n");
    if(szam > 999 || szam < 2){
        printf("Hiba tul kicsi vagy tul nagy szamot adtal meg (2-999).");
        return 0;
    }
    else{
        if(szam == tomb[szam-2])printf("A szam prim.");
        else printf("A szam nem prim.");
    }

    return 0;
}
