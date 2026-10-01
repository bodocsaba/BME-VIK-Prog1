#include <stdio.h>

double osszegzo(double *tomb, int meret){
    double osszeg = 0;
    for(int i=0;i<meret;i++)osszeg += tomb[i];
    return osszeg;
}

int main(){
    double tomb[10] = {1.5,3.1,4,7.5,11.4,25,65.5,100,12,8.25};
    printf("A tomb elemeinek osszege: %g",osszegzo(tomb,10));
    return 0;
}
