#include<stdio.h>

long int array[100005];

int main(){ // Binary search
	int N;
	int Q;
	scanf("%d", &N);
	scanf("%d", &Q);
	long int querrie;
	long int inic, fim, meio = 0;
	long int receive;

	for(int i = 0; i < N; i++){
		scanf("%ld", &receive);
		array[i] = receive;
	}

    long int save;
	for(int i = 0; i < Q; i++){
		scanf("%ld", &querrie);
        save = -1;
		inic = 0;
		fim = N - 1;
		while(inic <= fim){
			meio = (inic + fim)/2;
			if(array[meio] < querrie){
				inic = meio + 1;
			}
			else if(array[meio] > querrie){
				fim = meio - 1;
			}
			else{
                save = meio;
				fim = meio - 1;
			}
		}
		printf("%ld\n", save);
	}
	return 0;
}
