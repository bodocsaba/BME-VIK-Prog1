#include <stdio.h>

int main(){
    int szorzat = 1;
    int n = 8;
    while (n > 1) {   // Abban más mint az előző, hogy ott ahogy növeltük az n értékét úgy annyival szoroztuk a szorzat értékét is,
        szorzat *= n; // de itt már alapvetően az n értéke 8-ra van állítva és ahogy szorozzuk a szorzatot utana csökkentsük az n értékét
        n -= 1;       // a szorzat változó értéke, amikor az n változó éppen 3-ra változik: 6720
    }
    printf("%d\n", szorzat);
    return 0;
}
