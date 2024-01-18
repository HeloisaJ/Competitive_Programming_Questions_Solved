#include <stdio.h>
#include <math.h>

int main(){ // Etruscan Warriors Never Play Chess
    int i, t;
    scanf("%d", &t);
    for(i = 0; i < t; i++){
        long long int n;
        scanf("%lld", &n);
        int res = (-1 + sqrt(1 + 8 * n))/2;
        printf("%d\n", res);
    }
    return 0;
}