#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    printf("Muzeum II\n\n");
    int nap = 0;
    int latogatok = 0;
    int tomb[7] = {0};
    bool vanmeg = true;
    printf("Add meg a het napjat es szokozzel elvalasztva a latogatok szamat\n\n");
    while(vanmeg){
        scanf("%d %d",&nap,&latogatok);
        if(nap == 0 && latogatok == 0){
            vanmeg = false;
        }
        else if(nap >=1 && nap <=7){
            tomb[nap-1] += latogatok;
        }
        else{
            printf("Hiba, rossz nap erteket adtal meg.\n\n");
        }
    }
    int legkevesebb = tomb[0];
    int index = 0;
    for(int i=1;i<7;i++){
        if(tomb[i] < legkevesebb){
            legkevesebb = tomb[i];
            index = i;
        }
    }
    printf("%d",index+1);
    return 0;
}
