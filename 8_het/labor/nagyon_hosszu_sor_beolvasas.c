#include <stdio.h>
#include "debugmalloc.h"

int main(){
    char* tomb = NULL;
    int n = 0;
    char c;
    while(scanf("%c",&c) == 1 && c != '\n'){
        char* ujtomb = (char*)realloc(tomb, (n + 2) * sizeof(char));
        if(ujtomb == NULL){
            free(tomb);
            return 1;
        }
        tomb = ujtomb;
        tomb[n++] = c;
        tomb[n] = '\0';
    }
    for(int i=n-1;i>=0;--i)printf("%c",tomb[i]);
    printf("\n");
    free(tomb);
    return 0;
}
