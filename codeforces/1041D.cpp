#include<bits/stdc++.h>
using namespace std;

int n;
long h, maior;
vector<pair<long, long>> correntes;

int main(){ // Glider
	int xi, xf;
	cin >> n >> h;
	long distCorrente[n];
	for(int i = 0; i < n; i++){
		cin >> xi >> xf;
		correntes.push_back(make_pair(xi, xf));
		distCorrente[i] = xf - xi;
	}
	int i, rest = n - 1;
	long res = 0;
	maior = distCorrente[rest] + h;
	long dist = 0;
	for(i = rest - 1; i >= 0; i--){
		dist += correntes[i + 1].first - correntes[i].second;
		while(dist >= h){
			if(maior > res){
				res = maior;
			}
			maior -= distCorrente[rest];
			dist -= correntes[rest].first - correntes[rest - 1].second;
			rest--;
		}
		maior += distCorrente[i];
	}
	if(maior > res){
		res = maior;
	}
	cout << res << endl;
}
