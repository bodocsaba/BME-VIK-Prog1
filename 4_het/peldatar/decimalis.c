#include <stdio.h>

int dec_to_int(char *s){
    int szam;
    sscanf(s,"%d",&szam);
    return szam;
}

int dec_to_int2(char *s){
    int szam = 0;
    for(int i=0;s[i] != '\0';++i){
        szam *=10;
        szam += s[i] - '0';
    }
    return szam;
}

int main(){
    printf("%d",dec_to_int2("0")) ;
    return 0;
}
