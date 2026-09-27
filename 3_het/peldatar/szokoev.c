#include <stdio.h>

bool szokoeve(int x){
    return (x % 400 == 0) || (x % 100 != 0 && x % 4 == 0);
}
int main(){
    printf("Szokoev\n\n");
    int ev = 2020;
    if(szokoeve(ev))printf("Az ev %d: szokoev",ev);
    else printf("Az ev %d: nem szokoev",ev);
    return 0;
}
