#include<stdio.h>

int main(){ // Back to High School Physics
    int v, t;
    while(scanf("%d %d", &v, &t) == 2){
        t = t*2;
        int d = v*t;
        printf("%d\n", d);
    }
    return 0;
}