#include <stdio.h>
#include <math.h>

typedef struct Vektor{
    double x,y;
}Vektor;

double hossz(Vektor seb){
    return sqrt((seb.x*seb.x)+(seb.y*seb.y));
}

Vektor osszeg(Vektor seb1, Vektor seb2){
    return (Vektor){seb1.x+seb2.x,seb1.y+seb2.y};
}


int main(){
    Vektor seb1 = {1,2};
    Vektor seb2 = {-0.5,3};
    printf("A sebessegvektorok osszege: Sum = {%g m/s,%g m/s}\n",osszeg(seb1,seb2).x,osszeg(seb1,seb2).y);
    printf("Az eredo vektor hossza: %g m/s\n",hossz(osszeg(seb1,seb2)));
    return 0;
}
