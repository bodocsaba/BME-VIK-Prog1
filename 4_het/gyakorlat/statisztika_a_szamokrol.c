#include <stdio.h>

int main(){
    int tomb[10] = {0};
    int szam = 0;
    while(scanf("%d",&szam) == 1 && szam >=1 && szam <=10){
        tomb[szam-1]++;
    }
    printf("\n");
    for(int i=0;i<10;i++)printf("%2d: %d db\n",i+1,tomb[i]);
    return 0;
}
