#include <stdio.h>

typedef struct Parameter{
    double minimum,maximum;
}Parameter;

Parameter osszeg(Parameter rud1, Parameter rud2){
    return (Parameter) {rud1.minimum+rud2.minimum,rud1.maximum+rud2.maximum};
}
double atlag(Parameter rud1, Parameter rud2){
    return (osszeg(rud1,rud2).minimum+osszeg(rud1,rud2).maximum)/2;
}


int main(){
    Parameter rud1 = {999,1001};
    Parameter rud2 = {498,502};
    printf("A ket rud minimalis osszege: %g\n",osszeg(rud1,rud2).minimum);
    printf("A ket rud maximalis osszege: %g\n",osszeg(rud1,rud2).maximum);
    printf("A rudak atlaga: %g\n",atlag(rud1,rud2));
    return 0;
}
