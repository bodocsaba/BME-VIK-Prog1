#include <stdio.h>

// a)
void iterativ_elore(int *tomb, int meret){
    for(int i=0;i<meret;++i)printf("%d ",tomb[i]);
}
void iterativ_hatra(int *tomb, int meret){
    for(int i=meret-1;i>=0;--i)printf("%d ",tomb[i]);
}

// b)
void rekurziv_elore(int *tomb,int meret){
    if(meret == 0)return;
    printf("%d ",tomb[0]);
    rekurziv_elore(tomb+1,meret-1);
}
void rekurziv_hatra(int *tomb,int meret){
    if(meret == 0)return;
    printf("%d ",tomb[meret-1]);
    rekurziv_hatra(tomb,meret-1);
}

int main(){
    int tomb[10] = {1,2,3,4,5,6,7,8,9,10};
    iterativ_elore(tomb,10);
    printf("\n");
    iterativ_hatra(tomb,10);
    printf("\n");
    int tomb2[5] = {1,2,3,4,5};
    rekurziv_elore(tomb2,5);
    printf("\n");
    rekurziv_hatra(tomb2,5);
    return 0;
}
