#include <stdio.h>
#include <stdbool.h>

int rendezett_e(double *tomb, int meret){
    int osszevissza = 0;
    int csokkeno = 1;
    int novekvo = 2;
    bool novekvoe = true;
    bool csokkenoe = true;
    for(int i=0;i<meret-1;++i){
        if(tomb[i] < tomb[i+1])csokkenoe = false;
        if(tomb[i] > tomb[i+1])novekvoe = false;
    }
    if(!novekvoe && !csokkenoe)return osszevissza;
    else if(novekvoe)return novekvo;
    else if (csokkenoe)return csokkeno;
}

int main(){
    double tomb[10] = {2.2,5.4,6,12.01,15,22,31,40.5,55.9,62};
    double tomb2[10] = {67.2,55.3,40,24,12,11.12,5.9,3,2,1};
    double tomb3[10] = {2.2,5.4,10,4,14.25,22,31,40.5,55.9,57};
    int tipus = rendezett_e(tomb3,10);
    if(tipus == 2)printf("A tomb szigoruan monoton novekvo.");
    else if(tipus == 1)printf("A tomb szigoruan monoton csokkeno.");
    else printf("A tomb se nem monoton se nem csokkeno.");
    return 0;
}
