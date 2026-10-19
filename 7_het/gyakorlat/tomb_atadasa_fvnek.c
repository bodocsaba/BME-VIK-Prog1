#include <stdio.h>

void szetvalogat(int *tomb, int meret, int *paros, int *paros_meret, int *paratlan, int *paratlan_meret){
    *paros_meret = 0;
    *paratlan_meret = 0;
    for(int i=0;i<meret;++i){
        if(tomb[i] != 0 && tomb[i]%2 == 0)paros[(*paros_meret)++] = tomb[i];
        else if(tomb[i] != 0)paratlan[(*paratlan_meret)++] = tomb[i];
    }
}

void kiir(int *tomb, int meret){
    for(int i=0;i<meret;++i)printf("%d ",tomb[i]);
    printf("\n");
}

int main(){
    int tomb[10] = {0,1,2,3,4,5,6,7,8,9};
    int paros[10], paratlan[10];
    int paros_meret, paratlan_meret;
    szetvalogat(tomb,10,paros,&paros_meret,paratlan,&paratlan_meret);
    kiir(tomb,10);
    kiir(paros,paros_meret);
    kiir(paratlan,paratlan_meret);
    return 0;
}
