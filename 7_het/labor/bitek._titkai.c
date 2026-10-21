#include <stdio.h>

int main(){
    unsigned long szamok[8] = { 0U, 1931988508U, 581177634U, 581374240U,
                            581177632U, 581177634U, 1919159836U, 0U };
    for(int i=0;i<8;++i){
        printf("%d. ",i);
        for(int y=31;y>=0;--y){
            unsigned long szam = szamok[i];
            (szam >> y &1) == 1 ? printf("#") : printf(" ");
        }
        printf("\n");
    }
    return 0;
}
