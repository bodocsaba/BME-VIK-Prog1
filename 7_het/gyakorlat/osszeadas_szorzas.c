#include <stdio.h>

void osszeg_szorzat(double sz1, double sz2, double *osszeg, double *szorzat){
    *osszeg = sz1+sz2;
    *szorzat = sz1*sz2;
}

int main(){
    double osszeg,szorzat;
    osszeg_szorzat(10,20,&osszeg,&szorzat);
    printf("A ket szam osszege: %g\n",osszeg);
    printf("A ket szam szorzata: %g\n",szorzat);
    return 0;
}
