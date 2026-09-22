#include <stdio.h>

int main(){
    printf("Kasszak I.\n\n");
    int osszegzes[32] = {0};
    int kassza; int osszeg;
    printf("Add meg a kassza sorszamat es a fizetett osszeget\n\n");
    scanf("%d %d",&kassza,&osszeg);
    int osszbevetel = 0;
    while(kassza != 0 || osszeg != 0){
        osszegzes[kassza-1] += osszeg;
        osszbevetel +=osszeg;
        scanf("%d %d",&kassza,&osszeg);
    }
    printf("\n");
    for(int i=0;i<32;i++){
        if(osszegzes[i] > 0){
            printf("%d: %d Ft -> ez az osszbevetel %g%%-a\n",i+1,osszegzes[i],100.0*osszegzes[i]/osszbevetel);
        }
    }
    return 0;
}
