#include <stdio.h>

void kocka(double a, double *felulet, double *terfogat){
    *felulet = 6*a*a;
    *terfogat = a*a*a;
}

int main(){
    printf("Kocka - cim szerinti parameteratadas\n\n");
    double a = 2.7;
    double felulet,terfogat;
    kocka(a,&felulet,&terfogat);
    printf("A kocka  felszine F: %g\n",felulet);
    printf("A kocka terfogata V: %g",terfogat);
    return 0;
}
