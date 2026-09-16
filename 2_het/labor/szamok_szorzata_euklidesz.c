#include <stdio.h>

int main() {
    int a = 11220;
    int b = 2002;
    while (b > 0) {
        int temp = b; // a b változó értéke, amikor az a épp 374-re változik: 44
        b = a % b;
        a = temp;
    }

    printf("lnko = %d\n", a);
    return 0;
}
