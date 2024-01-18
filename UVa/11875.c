#include <stdio.h>

int main(){ // Brick Game
    int n, t, i, j;
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        scanf("%d", &t);
        int x;
        int cap = (t-1)/2;
        for(j = 0; j < t; j++){
            scanf("%d", &x);
            if(j == cap){
                cap = x;
            }
        }
        printf("Case %d: %d\n", i, cap);
    }
    return 0;
}