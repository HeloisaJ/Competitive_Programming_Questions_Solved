#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> ativ;

int main(){ // I AM VERY BUSY
    int t, n, ini, fim;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        for(int j = 0; j < n; j++){
            cin >> ini >> fim;
            ativ.push_back(make_pair(fim, ini));
        }
        sort(ativ.begin(), ativ.end());
        fim = ativ[0].first;
        int cont = 1;
        for(int j = 1; j < n; j++){
            if(ativ[j].second >= fim){
                fim = ativ[j].first;
                cont++;
            }
        }
        cout << cont << "\n";
        ativ.clear();
    }
}
