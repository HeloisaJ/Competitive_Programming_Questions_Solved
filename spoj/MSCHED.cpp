#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> vacas; // galoes, deadline
vector<bool> ocupado;

int main(){ //Milk Scheduling
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, g, d, maiorD = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> g >> d;
        vacas.push_back(make_pair(g, d));
        if(d > maiorD){
            maiorD = d;
        }
    }
    sort(vacas.begin(), vacas.end());
    ocupado.assign(maiorD, false);
    long long soma = 0;
    for(int i = n - 1; i >= 0; i--){
        if(!ocupado[vacas[i].second - 1]){
            ocupado[vacas[i].second - 1] = true;
            soma += vacas[i].first;
        }
        else{
            for(int j = vacas[i].second - 2; j >= 0; j--){
                if(!ocupado[j]){
                    ocupado[j] = true;
                    soma += vacas[i].first;
                    break;
                }
            }
        }
    }
    cout << soma << "\n";
}