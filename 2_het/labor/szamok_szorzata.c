#include <stdio.h>

int main(){
    printf("Szamok szorzata\n\n");
    int n = 1;
    int szorzat = 1;
    while (n<=8){
        szorzat *=n;
        n++;
    }
    printf("A 8 faktorialisa: %d",szorzat);
    return 0;
}
