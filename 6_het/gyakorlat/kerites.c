#include <stdio.h>
#include <math.h>
#include <stdbool.h>

typedef struct Pont{
    double x,y;
}Pont;

double tav(Pont p1, Pont p2){
    return sqrt((pow(p1.x-p2.x, 2) + pow(p1.y - p2.y,2)));
}

bool atfedike(Pont p1, Pont p2){
    return sqrt((pow(p2.x-p1.x, 2) + pow(p2.y - p1.y,2))) == 0;
}

Pont beolvas(void){
    Pont p;
    printf("Add meg a koordinata x es y ertekeit\n");
    scanf("%lf %lf",&p.x, &p.y);
    printf("\n");
    return p;
}

int main(){
    Pont p1 = beolvas();
    Pont p2 = beolvas();
    printf("A ket pont tavolsaga: %g\n",tav(p1,p2));
    if(atfedike(p1,p2))printf("A ket pont atfedi egymast.\n");
    else printf("A ket pont nem fedi egymast.\n");
    return 0;
}
