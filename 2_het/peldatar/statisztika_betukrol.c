#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Statisztika betukrol\n\n");
    int tomb[26] = {0};
    char betu;
    printf("Adj meg valami szoveget -1 ha vege\n\n");
    while(scanf("%c", &betu) == 1){
        if(betu >= 'A' && betu <= 'z'){
            tomb[betu - 'A']++;
        }
    }
    printf("\n");
    for(int i=0;i<26;i++){
        printf("%c: %d\n",'A'+i,tomb[i]);
    }
    return 0;
}
