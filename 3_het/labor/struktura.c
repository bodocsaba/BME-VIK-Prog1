#include <stdio.h>

typedef struct Pont{
    double x,y;
}Pont;

int main(){
    printf("Struktura - bemelegito\n\n");
    Pont p1 = {2.2,1.6};
    Pont p2;
    printf("Add meg a masik pont x es y koordinatajat\n");
    scanf("%lf %lf",&p2.x,&p2.y);
    Pont felezopont = {(p1.x+p2.x)/2,(p1.y+p2.y)/2};
    printf("\n");
    printf("A ketto pont felezopontjai F = {%g;%g}",felezopont.x,felezopont.y);
    return 0;
}
