#include<iostream>
using namespace std;

int main(){ // Quadrado Mágico (OBI 2007)
	int i, j, N;
	cin >> N;
	int quadrado[N][N];
	int sum = 0, p = 0, l = 0, n = 0, m = 0;

	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			cin >> quadrado[i][j];
		}
		sum += quadrado[i][j - 1];
	}
	
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			p += quadrado[i][j];
			l += quadrado[j][i];
		}

		if(sum != p || sum != l){
			sum = -1;
			break;
		}
		
		p = 0;
		l = 0;
	}

	if(sum != -1){
		for(i = 0; i < N; i++){
			n += quadrado[i][i];
			m += quadrado[i][N - i - 1];
		}

		if(sum != n || sum != m){
			sum = -1;
		}
	}

	cout << sum << endl;
	return 0;
}
