#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    printf("Nincsenek Egyformak - 100 random kulonbozo szam\n");
    srand(time(0));
    int szamok[100] = {-1};
    int random;
    bool egyenlo = false;
    int db = 0;

    while(db != 100){
        if(db % 10 == 0)printf("\n");
        random = rand()%10001; // Itt akkora számot adunk meg, amekkora legyen a legnagyobb random szám
        for(int y=db;y>=0;y--){
            if(random == szamok[y]){
                egyenlo = true;
            }
        }
        if(!egyenlo){
                printf("%5d ",random);
                szamok[db] = random;
                db++;
        }
        else{
            egyenlo = false;
        }
    }
    return 0;
}
