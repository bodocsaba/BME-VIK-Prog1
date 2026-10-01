#include <stdio.h>

int main(){
    printf("Add meg a honap szamat: ");
    int n;
    scanf("%d",&n);
    printf("\n");
    int tomb[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    printf("Ez a honap: %d napos\n\n",tomb[n-1]);
    int ev,honap,nap;
    printf("Adj meg egy ev.honap.nap-ot: ");
    scanf("%d %d %d",&ev,&honap,&nap);
    printf("\n");
    if((ev % 4 == 0 && ev % 100 != 0) || ev % 400 == 0)tomb[1] = 29;
    int hanyadik = 0;
    for(int i=0;i<honap-1;i++){
        hanyadik += tomb[i];
    }
    printf("Ez az ev %d. napja", hanyadik+nap);
    return 0;
}
