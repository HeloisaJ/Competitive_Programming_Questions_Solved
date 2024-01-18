#include<bits/stdc++.h>
using namespace std;

bool sobe;
int cont;
int loop[11234];

void compara(int x, int y){
	if((sobe && loop[x] > loop[y]) || (!sobe && loop[x] < loop[y])){
		cont++;
		sobe = !sobe;
	}
}

int main(){ // Loop Musical
	int n;
	while(cin >> n && n != 0){
		for(int i = 0; i < n; i++){
			cin >> loop[i];
		}
		cont = 0;
		if(loop[n - 1] > loop[0]){
			sobe = false;
		}
		else{
			sobe = true;
		}
		for(int i = 1; i < n; i++){
			compara(i - 1, i);
		}
		compara(n - 1, 0);
		cout << cont << endl;
	}
}
