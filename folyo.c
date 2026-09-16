#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    printf("Szigmon\n\n");
    double tomb[18]={0.1,1,1.5,1.7,2,2.3,2.8,4.5,9.8,12,14.1,13,11.9,8.7,6.1,3.5,1,0.5};
    double legnagyobb_meredekseg = 0;
    int tav,szazalek;
    for(int i=0;i<17;i++){
        double meredekseg = fabs(tomb[i+1]-tomb[i]);
        if(meredekseg > legnagyobb_meredekseg){
            legnagyobb_meredekseg = meredekseg;
            tav = (i+1)*2;
            if(tomb[i+1] > tomb[i])
                szazalek = round((tomb[i+1] - tomb[i])*100);
            else
                szazalek = round((tomb[i] - tomb[i+1])*100);
        }
    }
    printf("%d-%d meternel a legmeredekebb es %d %% a meredeksege",tav-2,tav,szazalek);
    return 0;
}

