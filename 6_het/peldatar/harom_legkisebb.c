#include <stdio.h>
#include <stdbool.h>

void buborekrendezes(int* tomb, int meret){
    for(int i=meret-1;i>0;--i){
        bool voltcsere = false;
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

void harom_legkisebb(int* forras, int meret){
    int cel[3];
    int db = 0;
    cel[db++] = forras[0];
    for(int i=1;i<meret && db < 3;++i){
        if(forras[i] != cel[db-1])cel[db++] = forras[i];
    }
    kiir(cel,db);
}

int main(){
    int tomb[10] = {1,1,1,3,3,4,5,2,2,2};
    buborekrendezes(tomb,10);
    kiir(tomb,10);
    harom_legkisebb(tomb,10);
    return 0;
}
