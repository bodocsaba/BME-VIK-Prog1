#include <stdio.h>

int main(){
    char sztring[] = "az alma piros.";
    printf("%s\n",sztring);
    sztring[0] = 'A';
    printf("%s\n",sztring);
    sztring[8] = 'P';
    printf("%s\n",sztring);
    int db = 0;
    for(int i=0;sztring[i] != '\0';++i)if(sztring[i] == 'i')db++;
    printf("%d db 'i' volt.",db);
    return 0;
}
