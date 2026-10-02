#include <stdio.h>

int rendezett_e(double *tomb, int meret){ // 0 ha osszevissza, 1 ha csokkeno, 2 ha novekvo
    int osszevissza = 0;
    int csokkeno = 1;
    int novekvo = 2;
    if(tomb[0] < tomb[1]){ // növekvő
        for(int i=1;i<meret-1;++i){
            if(tomb[i] > tomb[i+1])return osszevissza; // 0 - összevissza
        }
        return novekvo; // 2 - növekvő
    }
    else if(tomb[0] > tomb[1]){ // csökkenő
        for(int i=1;i<meret-1;++i){
            if(tomb[i] < tomb[i+1])return osszevissza; // 0 - összevissza
        }
        return csokkeno; // 1 - csökkenő
    }
}

int main(){
    double tomb[10] = {2.2,5.4,6,12.01,4.5,22,31,40.5,55.9,56};
    double tomb2[10] = {67.2,55.3,40,24,12,11.12,5.9,3,2,1};
    double tomb3[10] = {2.2,5.4,10,4,14.25,22,31,40.5,55.9,57};
    int tipus = rendezett_e(tomb2,10);
    if(tipus == 2)printf("A tomb szigoruan monoton novekvo.");
    else if(tipus == 1)printf("A tomb szigoruan monoton csokkeno.");
    else printf("A tomb se nem monoton se nem csokkeno.");
    return 0;
}
