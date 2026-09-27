#include <stdio.h>
#include <stdbool.h>

int osztokszama(int ev){
    int db = 0;
    for(int i=1;i<=ev;i++){
        if(ev % i == 0)db++;
    }
    return db;
}

bool vanbennehetes(int ev){
    bool van = false;
    int temp = ev;
    while(temp > 0 && !van){
        int szamjegy = temp % 10;
        if(szamjegy == 7)van = true;
        else temp /= 10;
    }
    return van;
}
bool legkozelebbi(int ev){
    return (osztokszama(ev) == 8) && (vanbennehetes(ev));
}

int main(){
    int ev = 2016;
    while(!legkozelebbi(ev-1))ev--;
    printf("A kapitany %d-ban szuletett es jelenleg %d eves.",ev-1,2016-(ev-1));
    return 0;
}
