#include <stdio.h>

void felosztas(int szam){
    if(szam < 1000){
        printf("%d",szam);
        return;
    }
    felosztas(szam/1000);
    printf(" %03d", szam % 1000);

}

int main(){
    felosztas(1000222);
    return 0;
}
