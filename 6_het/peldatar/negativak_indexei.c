#include <stdio.h>
#include <stdbool.h>

bool bennevan_e(int* indexek,int szam){
    for(int i=0;i<4;++i)if(szam == indexek[i])return true;
    return false;
}


int main(){
    double tomb[10] = {2.5,-69,5.4,-8,7.7,6,2.9,-10,-3,9.8};
    int indexek[4] = {1,3,7,8};
    for(int i=0;i<10;++i){
        if(!bennevan_e(indexek,i))
            printf("[%d]=%g ",i,tomb[i]);
    }
    return 0;
}
