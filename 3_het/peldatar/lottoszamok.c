#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    printf("Lottoszamok\n\n");
    srand(time(0));
    int tomb[90];
    int db = 0;
    for(int i=0;i<90;i++) tomb[i] = i+1;
    while(db != 5){
        int index = rand()%90 + 1;
        if(tomb[index] != 0){
            db++;
            printf("A(z) %d.szam kisorsolva: %d\n",db,tomb[index]);
            tomb[index] = 0;
        }
    }
    return 0;
}
