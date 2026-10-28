#include <stdio.h>
#include "debugmalloc.h"
#include <stdlib.h>

int main(){
    printf("Hany szam lesz?\n");
    int n = 0;
    printf("n: ");
    scanf("%d",&n);
    double* tomb = (double*) malloc(n*sizeof(double));
    if(tomb == NULL){
        printf("Hiba, nem sikerult memoriat foglalni.");
        return 1;
    }
    for(int i=0;i<n;++i){
        printf("%d szam: ",i+1);
        scanf("%lf",&tomb[i]);
        printf("\n");
    }
    for(int i=n-1;i>=0;--i)printf("%d szam: %g\n",i+1,tomb[i]);
    free(tomb);
    return 0;
}
