#include <stdio.h>

int main(){
    int tomb[10] = {0};
    int szam = 0;
    while(szam != -1){
        printf("Szam: ");
        scanf("%d",&szam);
        if(szam > 0 && szam < 11)tomb[szam-1]++;
        printf("\n");
    }
    for(int i=0;i<10;i++)printf("%2d: %d db\n",i+1,tomb[i]);
    return 0;
}
