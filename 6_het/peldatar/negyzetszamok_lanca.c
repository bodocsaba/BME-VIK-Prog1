#include <stdio.h>
#include <math.h>

int negyzetosszeg(int szam){
    if(szam == 1 || szam == 89)return szam;
    int osszeg = 0;
    while(szam > 0){
        int maradek = szam % 10;
        osszeg += maradek * maradek;
        szam /= 10;
    }
    szam = osszeg;
    return negyzetosszeg(osszeg);
}

void negyzetszam_lanc(int szam, int db){
    if(szam >= 10000){ // 10 000 ig tud csak futni
        printf("%d db szam volt ami 89-hez ert.",db);
        return;
    }
    int temp = negyzetosszeg(szam);
    if(temp == 89)db++;
    negyzetszam_lanc(szam+1, db);
}

int main(){
    negyzetszam_lanc(1,0);
    return 0;
}
