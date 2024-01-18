#include<iostream>
using namespace std;

int main(){ // Botas Trocadas
	int i, j, N, pares = 0;
	cin >> N;
	int tam [N];
	char tipo[N];

	for(i = 0; i < N; i++){
		cin >> tam[i];
		cin >> tipo[i];
	}

	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			if(tam[i] == tam[j] && tipo[i] != tipo[j] && tam[i] != 0){
				pares++;
				tam[i] = 0;
				tam[j] = 0;
			}
		}
	}

	cout << pares << endl;
	return 0;
}
