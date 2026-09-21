#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Tukorszamok\n\n");
    for(int i=100;i<=999;i++){
        int szazasok = i/100;
        int kettesek = (i%100)/10;
        int egyesek  = i % 10;
        if((szazasok == kettesek && kettesek == egyesek) || szazasok == egyesek){
            printf("%d\n",i);
        }
    }

    return 0;
}
