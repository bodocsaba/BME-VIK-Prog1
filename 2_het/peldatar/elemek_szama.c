#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Annyiadik\n\n");
    int tomb[10] = {1,3,2,7,4,11,9,25,6,12};
    int n;
    printf("A 10 elemu tomb hanyadik elemet szeretned kivalasztani?\n");
    printf("n: ");
    scanf("%d",&n);
    printf("\n");
    n = tomb[n-1];
    int kisebb = 0;
    int nagyobb = 0;
    for(int i=0;i<10;i++){
        if(tomb[i] < n){
            kisebb++;
        }
        else if(tomb[i] > n){
            nagyobb++;
        }
    }
    printf("A %d szamnal kisebb elemek szama: %d\n",n,kisebb);
    printf("A %d szamnal nagyobb elemek szama: %d",n,nagyobb);
    return 0;
}
