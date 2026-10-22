#include <stdio.h>
#include <stdbool.h>

void buborekrendezes(int* tomb, int meret){
    int voltcsere = false;
    for(int i=meret-1;i>0;--i){
        for(int y=0;y<i;++y){
            if(tomb[y] > tomb[y+1]){
                int temp = tomb[y];
                tomb[y] = tomb[y+1];
                tomb[y+1] = temp;
                voltcsere = true;
            }
        }
        if (!voltcsere)break;
    }
}

void kiir(int* tomb, int meret){
    for(int i=0;i<meret;++i)printf("%d ",tomb[i]);
    printf("\n");
}

int main(){
    int tomb[10] = {1,4,2,3,6,5,9,8,7,10};
    buborekrendezes(tomb,10);
    kiir(tomb,10);
    return 0;
}
