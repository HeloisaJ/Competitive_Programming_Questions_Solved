#include <stdio.h>

int main(){
    int n, b, h, w, price;
    scanf("%d %d %d %d", &n, &b, &h, &w);
    int cont = 0;
    int bed = 0;
    int value = 0;
    int menor = 0;
    int i, j;
    for(i = 0; i != h; i++){
        scanf("%d", &price);

        for(j = 0; j != w; j++){
            scanf("%d", &bed);
            if(bed >= n){
                cont++;
            }
        }
        
        if(cont > 0){
            value = price * n;
            if(menor == 0 || menor >= value){
                menor = value;
            }
        }
    }

    if(menor == 0 || menor > b){
        printf("stay home\n");
    }
    else{
        printf("%d\n", menor);
    }

    return 0;
}