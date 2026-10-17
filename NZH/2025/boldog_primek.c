#include <stdio.h>
#include <stdbool.h>

bool prim_e(int szam){
    for(int i=2;i<szam;++i){
        if(szam % i == 0)return false;
    }
    return true;
}

int negyzetosszeg(int szam){
    bool kisebbe = false;
    while(!kisebbe){
        int osszeg = 0;
        while(szam > 0){
            osszeg += (szam%10) * (szam%10);
            szam /= 10;
        }
        szam = osszeg;
        if(szam < 10)kisebbe = true;
    }
    return szam;
}

bool boldog_e(int szam){
   return prim_e(szam) && negyzetosszeg(szam) == 1;
}

int main(){
    int db = 0;
    for(int i=2;db != 10;++i){
        if(boldog_e(i))db++;
        if(db == 10)printf("%d",i);
    }
    return 0;
}
