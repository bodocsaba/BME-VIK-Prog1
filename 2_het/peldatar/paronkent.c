#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    printf("|---------|\n");
    printf("|Paronkent|\n");
    printf("|---------|\n\n");
    srand(time(0));
    int tomb[50];
    for(int i=0;i<50;i++){
        tomb[i] = rand() % 201;
    }
    int db_paros = 0;
    printf("Parok\n");
    printf("-----\n\n");
    for(int i=0;i<50;i++){
        for(int y=i+1;y<50;y++){
            if(tomb[i] == 0 && tomb[y] == 0){
                db_paros++;
                printf("%d. |%d| * 2 = |%d|\n",db_paros, tomb[i],tomb[y]);
            }
            else if(tomb[i] == 2*tomb[y]){
                db_paros++;
                printf("%d. |%d| * 2 = |%d|\n",db_paros, tomb[y],tomb[i]);
            }
            else if(tomb[i]*2 == tomb[y]){
                db_paros++;
                printf("%d. |%d| * 2 = |%d|\n",db_paros, tomb[i],tomb[y]);
            }
        }
    }
    if(db_paros == 0){
        printf("Nem volt ilyen paros.");
    }

    return 0;
}
