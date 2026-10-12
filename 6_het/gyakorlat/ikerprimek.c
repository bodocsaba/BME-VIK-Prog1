#include <stdio.h>
#include <stdbool.h>

bool prime(int szam){
    int oszto = 2;
    while(oszto < szam){
        if(szam % oszto == 0) return false;
        else oszto++;
    }
    return true;
}

int main(){
    int szam = 1;
    int db = 0;
    while(db < 60){
        szam++;
        if(prime(szam) && prime(szam+2))db++;
    }
    printf("A 60. ikerprim: (%d,%d)",szam,szam+2);
    return 0;
}
