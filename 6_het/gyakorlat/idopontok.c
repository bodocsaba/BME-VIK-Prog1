#include <stdio.h>

typedef struct ido{
    int ora,perc;
}ido;

void ido_kiir(ido i){
    printf("%02d:%02d\n",i.ora,i.perc);
}

ido ido_hozzaad(ido i,int p){
    i.perc += p;
    i.ora += i.perc / 60;
    i.perc = i.perc % 60;
    return i;
}

int ido_eltelt(ido i1, ido i2){
    return (i1.ora*60+i1.perc) - (i2.ora*60+i2.perc);
}

ido ido_kivon(ido i, int p){
    int osszeg = i.ora*60+i.perc-p;
    i.ora = osszeg / 60;
    i.perc = osszeg % 60;
    return i;
}

int main(){
    ido idopont = {15,45};
    ido_kiir(idopont);
    idopont = ido_hozzaad(idopont,30);
    ido_kiir(idopont);
    ido i1 = {16,30};
    ido i2 = {15,15};
    printf("%d perc telt el.\n",ido_eltelt(i1,i2));
    idopont = ido_kivon(idopont, 25);
    ido_kiir(idopont);
    return 0;
}
