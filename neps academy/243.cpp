#include<bits/stdc++.h>
using namespace std;

int n, m, cont;
vector<pair<pair<int, int>, pair<int, int>>> matriz;

int main(){ // Olimpíadas
	cin >> n >> m;
	int o, p, b;
    for(int i = 0; i < n; i++){
        matriz.push_back(make_pair(make_pair(0, 0), make_pair(0, 0)));
    }
	for(int i = 0; i < m; i++){
		cin >> o >> p >> b;
		matriz[o - 1].first.first++;
		matriz[p - 1].first.second++;
		matriz[b - 1].second.first++;
	}
    for(int i = 1; i <= n; i++){
        matriz[i - 1].second.second = - i;
    }
	sort(matriz.begin(), matriz.end());
	cont = 0;
	for(int i = n - 1; i >= 0; i--){
		cout << matriz[i].second.second * -1;
        if(i != 0){
            cout << " ";
        }
	}
	cout << "\n";
}
