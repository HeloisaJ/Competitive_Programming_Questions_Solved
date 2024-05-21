#include<bits/stdc++.h>
using namespace std;

vector<pair<long, long>> val;
int n, soma;

int busca(int p){
    int ini = 0, fim = n - 1, meio;
    while(ini <= fim){
        meio = (ini + fim)/2;
        if(val[meio].first == p){
            return meio;
        }
        else if(val[meio].first > p){
            fim = meio - 1;
        }
        else{
            ini = meio + 1;
        }
    }
    return -1;
}

int main(){ // Sum of Two Values
    int pos;
    long x;
    cin >> n >> soma;
    for(int i = 0; i < n; i++){
        cin >> x;
        val.push_back(make_pair(x, i));
    }
    sort(val.begin(), val.end());
    bool solution = false;
    for(int i = 0; i < n; i++){
        pos = busca(soma - val[i].first);
        if(pos != -1 && pos != i){
            cout << (val[i].second + 1) << " " << (val[pos].second + 1) << "\n";
            solution = true;
            break;
        }
    }
    if(!solution){
        cout << "IMPOSSIBLE" << "\n";
    }
}