#include <stdio.h>

/*
int maximum(int *tomb,int meret){
    int index = 0;
    for(int i=0;i<meret;++i)if(tomb[index]<tomb[i])index = i;
    return index;
}
*/

/*
int *maximum(int *tomb,int meret){
    int index = 0;
    for(int i=0;i<meret;++i)if(tomb[index]<tomb[i])index = i;
    return &tomb[index];
}
*/

int *maximum(int *tomb){
    int *index = tomb;
    for(int *p=tomb;p != tomb+10;++p)if(*index < *p) index = p;
    return index;
}

int main(){
    int tomb[10] = {2,4,7,11,14,5,62,32,75,19};
    int *max = maximum(tomb);
    printf("A legnagyobb elem indexe: %d, cime: %p",max-tomb,(void *)max);
    return 0;
}
