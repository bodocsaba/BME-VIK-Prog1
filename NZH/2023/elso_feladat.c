#include <stdio.h>
#include <stdbool.h>

int osztok_szama(int szam){
    int db = 0;
    for(int i=1;i<=szam;++i){
        if(szam % i == 0)db++;
    }
    return db;
}

int segedfv(int szamjegy){
    int hossz[11] = {5,3,5,5,4,2,3,3,5,6};
    return hossz[szamjegy];
}

int osszeg(int szam){
    int Osszeg = 0;
    while(szam > 0){
        int szamjegy = szam % 10;
        Osszeg += segedfv(szamjegy);
        szam /= 10;
    }
    return Osszeg;
}

int main(){
    bool van = false;
    for(int i=1000;i<=9999;++i){
        if(osszeg(i) == 14 && osztok_szama(i) == 14){
            printf("%d\n",i);
            van = true;
        }
    }
    if(!van)printf("Nincs ilyen szam.\n");
    return 0;
}
