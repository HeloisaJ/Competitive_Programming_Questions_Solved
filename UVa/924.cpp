#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> grafo;
vector<bool> visited;
pair<int, int> maior; // max, day

void calculoBfs(int ini){
    queue<int> q;
    int p, cont = 1, soma = 0, d = 1;
    q.push(ini);
    visited[ini] = true;

    while(!q.empty()){
        p = q.front();
        q.pop();

        cont--;
        for(int u: grafo[p]){
            if(!visited[u]){
                visited[u] = true;
                q.push(u);
                soma++;
            }
        }

        if(cont == 0){
            cont += soma;
            if(maior.first < soma){
                maior.first = soma;
                maior.second = d;
            }
            soma = 0;
            d++;
        }
    }
}

int main(){ // Spreading The News
    int e, n, x, t;
    cin >> e;

    grafo.assign(e, vector<int>());
    for(int i = 0; i < e; i++){
        cin >> n;
        for(int j = 0; j < n; j++){
            cin >> x;
            grafo[i].push_back(x);
        }
    }

    cin >> t;
    for(int k = 0; k < t; k++){
        cin >> x;
        visited.assign(e, false);
        maior.first = 0;
        maior.second = 0;
        calculoBfs(x);
        if(maior.first == 0){
            cout << 0;
        }
        else {
            cout << maior.first << " " << maior.second;
        }
        cout << "\n";
    }
}