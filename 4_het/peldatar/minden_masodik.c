#include <stdio.h>

void minden_masodik(int *tomb, int meret){
    for(int i=meret-2;i>=0;i-=2)printf("%d. %d\n",i+1,tomb[i]);
}

int main(){
    int tomb[10] = {10,20,30,40,50,60,70,80,90,100};
    minden_masodik(tomb,10);
    return 0;
}
