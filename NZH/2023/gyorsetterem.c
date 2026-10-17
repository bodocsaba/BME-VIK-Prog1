#include <stdio.h>
#include <string.h>

typedef struct Etel{
    char nev[30+1];
    int db;
}Etel;

int kereses(Etel *etel, int meret, char *Nev){
    for(int i=0;i<meret;++i){
        if(strcmp(etel[i].nev, Nev) == 0) return i;
    }
    return -1;
}

int main(){
    Etel etel[5] = {
                {"hamburger",5},
                {"sajtburger",3},
                {"veganburger",0},
                {"hotdog",2},
                {"gyros",1}
    };
    char rendeles[30+1];
    int adag = 0;
    while(scanf("%d %30s",&adag,rendeles) == 2){
        int index = kereses(etel,5, rendeles);
        if(index != -1 && etel[index].db >= adag){
            printf("Tessek\n");
            etel[index].db -= adag;
        }
        else if(index != -1)printf("Nincs annyi\n");
        else printf("Ma nincs a kinalatban\n");
    }
    return 0;
}
