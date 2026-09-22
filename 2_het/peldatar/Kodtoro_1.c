#include <stdio.h>

int main(){
    printf("Kodtoro I.\n\n");
    int betuk[26] = {0};
    char c; int ossz = 0;
    while(scanf(" %c",&c) == 1){
        if(c <= 'Z' && c >= 'A'){
            betuk[c-'A']++;
            ossz++;
        }
    }
    for(int i=0;i<26;i++){
        if(betuk[i] > 0){
            printf("%c: %d db, %g%%\n",'A'+i,betuk[i],100.0*betuk[i]/ossz);
        }
    }
    return 0;
}
