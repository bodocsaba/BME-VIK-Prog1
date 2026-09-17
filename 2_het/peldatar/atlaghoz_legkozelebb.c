#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Atlaghoz legkozelebb\n\n");
    int tomb[20] = {42, 17, 89, 3, 65, 22, 91, 14, 58, 73, 5, 34, 88, 12, 60, 27, 99, 50, 8, 76};
    double atlag = 0;
    for(int i=0;i<20;i++)
        atlag += tomb[i];
    atlag /= 20;
    int legkozelebb = tomb[0];
    double legkozelebb_tav = atlag - tomb[0];
    if(legkozelebb_tav < 0)
            legkozelebb_tav *= -1;
    for(int i=1;i<20;i++){
        double temp = atlag - tomb[i];
        if(temp < 0)
            temp *= -1;
        if(temp < legkozelebb_tav){
            legkozelebb = tomb[i];
            legkozelebb_tav = temp;
        }
    }
    printf("Az atlag: %g\n",atlag);
    printf("A legkozelebbi szam: %d\n",legkozelebb);
    printf("Tav: %g\n",legkozelebb_tav);

    return 0;
}
