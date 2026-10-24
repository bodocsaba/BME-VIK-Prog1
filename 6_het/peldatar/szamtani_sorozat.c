#include <stdio.h>

double iterativ_szamtani(int n, double kezdo, double diff){
    if(n < 2)return kezdo;
    for(int i=1;i<n;++i)kezdo += diff;
    return kezdo;
}

double rekurziv_szamtani(int n, double kezdo, double diff){
    if(n < 2)return kezdo;
    return rekurziv_szamtani(n-1, kezdo+diff, diff);
}

int main(){
    printf("5.elem: %g\n",iterativ_szamtani(5,1,2));
    printf("5.elem: %g\n",rekurziv_szamtani(10,2,2));
    return 0;
}
