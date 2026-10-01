#include <stdio.h>

/* 1.feladat
int kereses(int *tomb, int meret, int szam){
    for(int i=0;i != meret;++i){
        if(tomb[i] == szam) return i;
    }
    return -1;
}
*/

/* 2.feladat
int *kereses(int *tomb, int meret, int szam){
    for(int i=0;i<meret;++i){
        if(tomb[i] == szam)return &tomb[i];
    }
    return NULL;
}
*/
// 3.feladat
int *kereses(int *t, int szam){
    for(int *p=t;p != t+10;++p){
        if(t[*p] == szam)return &t[*p];
    }
    return NULL;
}

int main(){
    int tomb[10] = {1,2,3,4,5,6,7,8,9,10};
    int *index = kereses(tomb,10);
    for(int i=0;i<10;i++)printf("%d. %d\n",i+1,tomb[i]);
    printf("\n");
    if(index != NULL)printf("memoria cim: %p, index: %d",(void*)index,*index);
    else printf("Nincs talalat.");
    return 0;
}
