#include <stdio.h>
#include "debugmalloc.h"
#include <stdlib.h>

int main(){
    double* tomb = NULL;
    int n = 0;
    double szam;
    while(scanf("%lf",&szam) == 1 && szam != -1){
        double* ujtomb = (double*)realloc(tomb, (n + 1) * sizeof(double));
        if(ujtomb == NULL){
            free(tomb);
            return 1;
        }
        tomb = ujtomb;
        tomb[n] = szam;
        n++;
    }
    for(int i=n-1;i>=0;--i)printf("%d szam: %g\n",i+1,tomb[i]);
    free(tomb);
    return 0;
}
