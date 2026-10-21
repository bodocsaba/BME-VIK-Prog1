#include <stdio.h>

int main(){
    unsigned long szam = 29;
    for(int i=31;i>=0;--i){
        printf("%d", szam >> i &1);
    }
    return 0;
}
