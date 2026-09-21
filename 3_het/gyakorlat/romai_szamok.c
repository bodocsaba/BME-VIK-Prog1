#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Adj meg egy szamot 1 es 99 kozott");
    int szam;
    printf("szam: ");
    scanf("%d",&szam);
    printf("\n");
    printf("%d romai szamkent: ",szam);
    int tizesek = szam / 10;
    int egyesek = szam % 10;
    if(tizesek < 1);
    else if(tizesek >= 1 && tizesek <= 3)
        for(int i=1;i<=tizesek;i++)printf("X");
    else if(tizesek == 4 )printf("XL");
    else if(tizesek >= 5 && tizesek <= 8){
        printf("L");
        for(int i=5;i<tizesek;i++)
            printf("X");
    }
    else if(tizesek == 9 )printf("XC");
    else if(tizesek == 10)printf("C");
    if(egyesek > 0 && egyesek <1)egyesek *= 10;
    if(egyesek == 0);
    else if(egyesek >=1 && egyesek <=3)
        for(int i=1;i<=egyesek;i++)printf("I");
    else if(egyesek == 4 ) printf("IV");
    else if(egyesek >= 5 && egyesek <= 8){
        printf("V");
        for(int i=5;i<egyesek;i++)
            printf("I");
    }
    else if(egyesek == 9 )printf("IX");
    return 0;
}
