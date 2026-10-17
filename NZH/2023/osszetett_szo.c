#include <stdio.h>
#include <stdbool.h>
#include <string.h>

char *szavak[] = {"alma","kor","uveg","szemuveg","szem","mos","alma", NULL};

bool benne(char *szo){
    for(int i=0;szavak[i] != NULL;++i){
        if(strcmp(szavak[i],szo) == 0)return true;
    }
    return false;
}

int osszetett(char *Szo){
    int hossz = strlen(Szo);
    for(int i=1;i<hossz;++i){
        char eleje[30+1],vege[30+1];
        strcpy(eleje,Szo);
        eleje[i] = '\0';
        strcpy(vege,Szo+i);
        if(benne(eleje) && benne(vege)) return i;
    }
    return 0;
}

int main(){
    char Szo[30+1];
    scanf("%s",Szo);
    int vagas = osszetett(Szo);
    if(vagas != 0)printf("Osszetett szo, a %d. betunel kell elvagni",vagas);
    else printf("Nem osszetett szo.\n");
    return 0;
}
