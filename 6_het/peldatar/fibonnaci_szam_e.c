#include <stdio.h>
#include <stdbool.h>

bool iterativ_fib_e(int szam){
    if(szam < 0) return 0;
    if(szam == 0 || szam == 1) return 1;
    int a = 0;
    int b = 1;
    int c = a+b;
    while(c < szam){
        a = b;
        b = c;
        c = a+b;
    }
    return c == szam;
}

bool rekurziv_fib_e(int a, int b, int szam){
    if(b == szam) return true;
    if(b > szam)  return false;
    return rekurziv_fib_e(b,a+b,szam);
}

int main(){
    int szam;
    printf("szam: ");
    scanf("%d",&szam);
    if(iterativ_fib_e(szam))printf("Ez fibonacci szam.\n\n");
    else printf("Ez nem fibonacci szam.\n\n");
    if(rekurziv_fib_e(0,1,szam))printf("Ez fibonacci szam.");
    else printf("Ez nem fibonacci szam.");
    return 0;
}
