#include<bits/stdc++.h>
using namespace std;

long valores[212345];
multiset<long> torres;

int main(){ // Towers
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, pos;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> valores[i];
    }
    torres.insert(valores[0]);
    long maiorTorre = valores[0];
    for(int i = 1; i < n; i++){
        if(valores[i] >= maiorTorre){
            torres.insert(valores[i]);
            maiorTorre = valores[i];
        }
        else{
            if(torres.size() > 1){
                auto it = torres.upper_bound(valores[i]);
                it++;
                if(it == torres.end()){
                    maiorTorre = valores[i];
                }
                it--;
                torres.erase(it);
            }
            else{
                torres.erase(torres.begin());
                maiorTorre = valores[i];
            }
            torres.insert(valores[i]);
        }
    }
    cout << torres.size() << "\n";
}