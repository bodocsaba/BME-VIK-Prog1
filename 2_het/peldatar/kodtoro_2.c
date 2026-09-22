#include <stdio.h>

int main(){
    printf("Kodtoro II.\n\n");
    int szamok_db['9' - '0'] = {0};
    char szamok; int ossz = 0;
    while(scanf(" %c",&szamok) == 1){
        if(szamok >= '0' && szamok <= '9'){
            szamok_db[szamok-'0']++;
            ossz++;
        }
    }
    int i = 0;
    for(int y='1'-'0';y<'9'-'0';y++){
        if(szamok_db[y] > szamok_db[i]){
            i = y;
        }
    }
    printf("\n");
    printf("%c: %d, %g%%",'0'+i,szamok_db[i],100.0*szamok_db[i]/ossz);
    return 0;
}
