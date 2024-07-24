#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

vector<ll> somas;
int n, m;
ll doces[212345];
ll soma, d;

void calculo(){
    d = 1;
    ll save;
    for(int i = 0; i < n; i++){

        if(m == 1){
            if(i == 0){
                soma += doces[i];
                save = doces[i];
            }
            else{
                soma += save + doces[i];
                save += doces[i];
            }
        }
        else{

            soma += doces[i];

            if(i != 0 && i % m == 0){
                d++;
            }

            if(d == 1){
                somas.push_back(0);
            }
            else if(d == 2){
                somas.push_back(doces[i - m]);
                soma += somas.back();
            }    
            else{
                somas.push_back(somas[i - m] + doces[i - m]);
                soma += somas.back();
            }

        }

        cout << soma;

        if(i < n - 1){
            cout << " ";
        }
    }
}

int main(){ // Sweets Eating
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> doces[i];
    }

    sort(doces, doces + n);

    soma = 0;
    calculo();

    cout << "\n";
}