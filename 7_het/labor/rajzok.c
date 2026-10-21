#include <stdio.h>

void torol(unsigned long int *tomb, int meret){
    for(int i=0;i<meret;++i){
        tomb[i] = 0;
    }
}

void bit_allit(unsigned long int *tomb, int meret, int x, int y){
    tomb[y] = tomb[y] | (1UL << x);
}

void kirajzol(unsigned long *tomb,int meret) {
    for (int y = 0; y < 24; ++y) {
        printf("%2d. ", y + 1);
        for (int x = 0; x < 32; ++x) {
            (tomb[y] >> x &1) == 1 ? printf("#") : printf(" ");
        }
        printf("\n");
    }
}
int main(){
    unsigned long int szamok[24];
    torol(szamok,24);
    for(int x=0;x<32;++x){
        bit_allit(szamok,24,x,0);
        bit_allit(szamok,24,x,23);
    }
    for(int y=1;y<23;++y){
        bit_allit(szamok,24,0,y);
        bit_allit(szamok,24,31,y);
    }
    kirajzol(szamok,24);
    return 0;
}
