#include <stdio.h>

int main(){
    printf("Tombok frissito\n\n");
    double tomb[10] = {1.5,-2.2,3,-4.9,5.25,-6.6,7.4,-8,9,-10.1};
    printf("Osszesen 10 szam van.\n");
    for(int i=0;i<10;i++)
        printf("[%d]=%g ",i,tomb[i]);
    int neg_tomb[10];
    int db = 0;
    for(int i=0;i<10;i++){
        if(tomb[i] < 0){
            neg_tomb[db] = i;
            db++;
        }
    }
    printf("\n\n");
    printf("Ebbol %d szam negativ.\n",db);
    int y = 0;
    for(int i=0;i<10;i++){
        if(i == neg_tomb[y]){
            printf("[%d]=%g ",i,tomb[i]);
            y++;
        }
    }
    return 0;
}
