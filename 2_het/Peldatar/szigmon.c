#include <stdio.h>

int main(){
    printf("Szigmon\n\n");
    int tomb_1[10]={2,3,13,20,21,42,45,50,70,73};
    int tomb_2[10]={72,55,54,49,37,25,11,6,4,2};
    int tomb_3[10]={3,1,15,14,25,72,32,45,62,80};
    int szigmon = 0;
    for(int i=0;i<10-1;i++){
        if(tomb_1[i] < tomb_1[i+1]) //a tomb_(1,2,3) nevet átírod amelyiket éppen tesztelni szeretnéd
            szigmon++;
        else if(tomb_1[i] > tomb_1[i+1])
            szigmon--;
        else
            szigmon = 0;
    }
    if(szigmon == 9)
        printf("Az elso tomb szigoruan monoton novekvo.");
    else if(szigmon == -9)
        printf("Az elso tomb szigoruan monoton csokkeno.");
    else
        printf("Az elso tomb se nem csokkeno es se nem novekvo");
    return 0;
}

