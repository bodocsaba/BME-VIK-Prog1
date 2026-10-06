#include <stdio.h>
#include <stdbool.h>

int main(){
    char tomb[] = "alma";
    bool egyedi = true;
    printf("Karakterek, amik pontosan egyszer fordulnak elo\n");
    for(int i=0;tomb[i] != '\0';++i){
        int elofordulas = 0;
        for(int y=0;tomb[y] != '\0';++y){
            if(tomb[i] == tomb[y])elofordulas++;
        }
        if(elofordulas <= 1){
            egyedi = false;
            printf("[%c] ",tomb[i]);
        }
    }
    printf("\n");
    if(egyedi)printf("Nincsenek a tombben egyedi karakterek.");
    return 0;
}
