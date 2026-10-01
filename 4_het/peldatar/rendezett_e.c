#include <stdio.h>

double *rendezett_e(double *tomb, int meret){
    if(tomb[0] > tomb[1]){ // csökkenő
        for(int i=1;i<meret-1;i++)if(tomb[i] < tomb[i+1])return &tomb[i+1];}
    else if(tomb[0] < tomb[1]){ // növekvő
        for(int i=1;i<meret-1;i++)if(tomb[i] > tomb[i+1])return &tomb[i+1];}
    return NULL;
}

int main(){
    double tomb[10] = {2.2,5.4,10,12.01,4.5,22,31,40.5,55.9,60};
    double tomb2[10] = {67.2,55.3,23,24,12,11.12,5.9,3,2,1};
    double tomb3[10] = {2.2,5.4,10,12.01,14.25,22,31,40.5,55.9,60};
    double *t = rendezett_e(tomb2,10); // lehet próbálgatni másik tömbökkel is.
    int index = t-tomb2;               // *t és indexnél is azonos tömb nevét kell megadni.
    if(t != NULL)printf("A tomb hibas eleme: %g, indexe: %d, cime: %p\n",*t,index,(void *)t);
    else printf("A tomb rendezett volt.");
    return 0;
}
