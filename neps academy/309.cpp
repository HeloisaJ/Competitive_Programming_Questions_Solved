#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> lista;
bool ligacoes [1123][1123];
int n, m, cont;
bool alunos[1123];

void calcdfs(int v){
    alunos[v] = true;
    for(int i = 0; i < lista[v].size(); i++){
        if(ligacoes[v][lista[v][i]]){
            ligacoes[v][lista[v][i]] = false;
            ligacoes[lista[v][i]][v] = false;
            calcdfs(lista[v][i]);
        }
    }
}

int main(){ // Gincana (OBI 2011)
	cin >> n >> m;
	int p1, p2;
    lista.assign(n + 1, vector<int>());
    memset(ligacoes, false, sizeof(ligacoes));
	for(int i = 0; i < m; i++){
		cin >> p1 >> p2;
        if(!ligacoes[p1][p2]){
		    lista[p1].push_back(p2);
            lista[p2].push_back(p1);
            ligacoes[p1][p2] = true;
            ligacoes[p2][p1] = true;
        }
	}
    cont = 0;
    memset(alunos, false, sizeof(alunos));
    for(int i = 1; i <= n; i++){
        if(!alunos[i]){
            calcdfs(i);
            cont++;
        }
    }
    cout << cont << "\n";
}
