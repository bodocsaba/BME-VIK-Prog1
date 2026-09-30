#include <string.h>
#include <stdio.h>


int main(){
    char keresztnev[5];
    fgets(keresztnev, sizeof(keresztnev),stdin); // biztonsagosabb
    // gets(keresztnev); // nem ajanlott
    for(int i=0;keresztnev[i] != '\0';++i)printf("%c\n",keresztnev[i]);
    return 0;
}