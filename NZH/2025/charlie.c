#include <stdio.h>
#include <string.h>

typedef struct fagyi{
    char izek[21];
    int gombocok;
}fagyi;

int kereses(fagyi *tomb, int meret, char *iz){
    for(int i=0;i<meret;++i){
        if(strcmp(tomb[i].izek,iz) == 0) return i;
    }
    return -1;
}

int main(){
    fagyi tomb[6] = {
                     {"pisztacia",5},
                     {"vanilia",2},
                     {"tutti-frutti",0},
                     {"karamell",3},
                     {"rumosdio",10},
                     {"kave",1},
    };
    char Izek[21];
    printf("Milyen fagyit szeretnel?\n");
    while(scanf(" %20[^\n]",&Izek) == 1){
        int index = kereses(tomb,6,Izek);
        if(index != -1 && tomb[index].gombocok > 0){
            printf("Sikeres vasarlas\n");
            tomb[index].gombocok--;
        }
        else if(index != -1 && tomb[index].gombocok == 0){
            printf("Kifogyott\n");
        }
        else printf("Nincs ilyen iz\n");
    }
    return 0;
}
