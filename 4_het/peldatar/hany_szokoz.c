#include <stdio.h>

int main(){
    char mondat[100];
    printf("Adj meg egy mondatot\n");
    fgets(mondat,sizeof(mondat),stdin);
    int db = 0;
    for(int i=0;mondat[i] != '\0';++i){
        if(mondat[i] == ' ')db++;
        else printf("%c",mondat[i]);
    }
    printf("%d db szokoz volt.",db);
    return 0;
}
