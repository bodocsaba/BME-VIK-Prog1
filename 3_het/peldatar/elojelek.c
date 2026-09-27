#include <stdio.h>
#include <stdbool.h>

bool egyezike(double a, double b){
    return (a < 0 && b < 0) || (a > 0 && b > 0);
}
int main(){
    printf("Elojelek\n\n");
    double n = 250.32;
    double m = -562.1;
    if(egyezike(n,m))printf("A ket szam elojele megegyezik.");
    else printf("A ket szam elojele kulonbozo.");
    return 0;
}
