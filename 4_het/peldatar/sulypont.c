#include <stdio.h>

typedef struct Pont{
    double x,y,z;
}Pont;

Pont sulypont(Pont *tomb, int meret){
    Pont suly = {0,0,0};
    if(meret <= 0)return suly;
    for(int i=0;i<meret;++i){
        suly.x += tomb[i].x;
        suly.y += tomb[i].y;
        suly.z += tomb[i].z;
    }
    suly.x /= meret;
    suly.y /= meret;
    suly.z /= meret;
    return suly;
}

int main(){
    Pont tomb[2] = {{2.2,3.5,7},{5,1.2,0}};
    Pont suly = sulypont(tomb,2);
    printf("sulypont: {%g,%g,%g}",suly.x,suly.y,suly.z);
    return 0;
}
