#include <stdio.h>
#include <stdbool.h>

bool maganhangzo_e(char c){
    return c =='a' || c =='e' || c =='i' || c =='o' || c =='u' ||
           c =='A' || c =='E' || c =='I' || c =='O' || c =='U';
}

int main(){
    char c;
    while (scanf("%c", &c) != EOF){
        if (maganhangzo_e(c) && c >= 'a')
            printf("%cv%c", c, c);
        else if(maganhangzo_e(c) && c <= 'Z')
            printf("%cv%c", c, c+32);
        else
            printf("%c", c);
    }
    return 0;
}
