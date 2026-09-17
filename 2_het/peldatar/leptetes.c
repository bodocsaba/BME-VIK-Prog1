#include <stdio.h>

int main(){
    printf("Leptetes\n\n");
    int v[10] = {1,2,3,4,5,6,7,8,9,10};
    for(int i=1;i<=3;i++){
        for(int y=0;y<10;y++){
            int temp = v[y];
            v[y] = v[y+1];
            v[y+1] = temp;
        }
    }
    for(int i=0;i<10;i++){
        printf("%d ",v[i]);
    }

    return 0;
}

