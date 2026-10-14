#include <stdio.h>

int fib(int n){
    if(n < 2)return n;
    return fib(n-2) + fib(n-1);
}

int main(){
    printf("Fib 10: %d\n",fib(10)); // Mivel a fv. hívások száma exponenciálisan nő
    return 0;                       // így magas lesz a futási idő fib(45)nél
}
