#include <stdio.h>

int maximum(int a, int b){
    if(a > b) return a;
    else return b;
}
int minimum(int a, int b){
    if(a < b) return a;
    else return b;
}
int korlatoz(int szam, int a, int b){
    int kisebb  = minimum(a,b);
    int nagyobb = maximum(a,b);
    if(szam >= kisebb && szam <= nagyobb)return szam;
    else if(szam < kisebb)return kisebb;
    else return nagyobb;
}

int main(){
    int a = 25000;
    int b = 6500;
    int szam_1 = 5000;
    int szam_2 = 12500;
    int szam_3 = 36230;
    printf("Nagyobbik szam: %d\n",maximum(a,b));
    printf("Kisebbik  szam: %d\n",minimum(a,b));
    printf("%d\n",korlatoz(szam_1,a,b));
    printf("%d\n",korlatoz(szam_2,a,b));
    printf("%d\n",korlatoz(szam_3,a,b));
    return 0;
}
