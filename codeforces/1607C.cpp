#include<bits/stdc++.h>
using namespace std;

long a[212345];

int main(){ // Minimum Extraction
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t, n;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        for(int j = 0; j < n; j++){
            cin >> a[j];
        }
        sort(a, a + n);
        int adicionar, soma = a[0], maior = a[0];
        for(int j = 1; j < n; j++){
            adicionar = a[j] - soma;
            if(adicionar > maior){
                maior = adicionar; 
            }
            soma += adicionar;
        }
        cout << maior << "\n";
    }
}