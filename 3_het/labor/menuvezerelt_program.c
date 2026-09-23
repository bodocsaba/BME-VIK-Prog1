#include <stdio.h>

int alapertek(int x){
    return 1;
}
int hozzaad(int x){
    return x+1;
}
int megfordit(int x){
    return x*-1;
}
int szorzas(int x){
    return x*2;
}

int main(){
    int a = 1;
    int menupont;
    do{
        printf("a: %d\n",a);
        printf("0. Alapertek visszaallitasa (a = 1)\n"
               "1. Hozzaad 1-et\n"
               "2. Megforditja az elojelet\n"
               "3. Szorozza 2-vel\n"
               "9. Kilepes\n");
        printf("\n");
        scanf("%d",&menupont);
        switch(menupont){
            case 0: a = alapertek(a);break;
            case 1: a = hozzaad(a);break;
            case 2: a = megfordit(a);break;
            case 3: a = szorzas(a);break;
            case 9: printf("Program vege.");break;
            default: printf("Rossz adat!\n");break;
        }
    }while(menupont != 9);
    return 0;
}
