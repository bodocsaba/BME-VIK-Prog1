#include <stdio.h>
#include <stdbool.h>
#include <math.h>

typedef struct Kor{
    double x,y,r;
}Kor;

bool atfedike(Kor k1, Kor k2){
    return sqrt(pow(k1.x-k2.x,2) + pow(k1.y-k2.y,2)) < k1.r+k2.r;
}

Kor beolvas(void){
    Kor adatok;
    printf("Add meg x,y es sugar ertekeit\n");
    scanf("%lf %lf %lf",&adatok.x,&adatok.y,&adatok.r);
    printf("\n");
    return adatok;
}

int main(){
    Kor k1 = beolvas();
    Kor k2 = beolvas();
    if(atfedike(k1,k2))printf("Atfedik egymast.");
    else printf("nem fedik egymast.");
    return 0;
}
