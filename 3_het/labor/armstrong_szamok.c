#include <stdio.h>
#include <stdbool.h>

int szamjegyekszama(int szam){
    int db = 0;
    if(szam == 0) return 1;
    while(szam > 0){
        szam /= 10;
        db++;
    }
    return db;
}

int hatvanyozo(int szamjegy, int db){
    int osszeg = szamjegy;
    for(int i=1;i<db;i++)osszeg *= szamjegy;
    return osszeg;
}

int szamjegyekosszege(int szam){
    int osszeg = 0;
    int temp = szam;
    int db = szamjegyekszama(szam);
    while(temp > 0){  // jobbról balra megyünk végig a számjegyeken
        int szamjegy = temp % 10;
        osszeg += hatvanyozo(szamjegy,db);
        temp /= 10;
    }
    return osszeg;
}
bool armstrongszame(int szam){
    return szamjegyekosszege(szam) == szam;
}
int main(){
    printf("Armstrong-szamok\n\n");
    for(int i=0;i<2000;i++){
        if(armstrongszame(i))printf("%d szam: Armstrong szam\n",i);
    }
    return 0;
}
