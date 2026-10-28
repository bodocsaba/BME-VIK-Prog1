#include <stdio.h>
#include "debugmalloc.h"

char *beolvas(){
    static char b;
    scanf("%c",&b);
    if(b == '\n') return NULL;
    else return &b;
}

int main(){
    char* tomb = NULL;
    int n = 0;
    char* c;
    while((c = beolvas()) != NULL){
        char* ujtomb = (char*)realloc(tomb, (n + 2) * sizeof(char));
        if(ujtomb == NULL){
            free(tomb);
            return 1;
        }
        tomb = ujtomb;
        tomb[n++] = *c;
        tomb[n] = '\0';
    }
    for(int i=n-1;i>=0;--i)printf("%c",tomb[i]);
    printf("\n");
    free(tomb);
    return 0;
}
