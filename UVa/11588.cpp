#include<bits/stdc++.h>
using namespace std;

int r, c, n, m;
map<char, int> letras;

int main(){ // Image Coding
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> r >> c >> m >> n;

        char l;
        int maior = 0;
        for(int j = 0; j < r; j++){
            for(int k = 0; k < c; k++){
                cin >> l;
                letras[l]++;

                if(letras[l] > maior){
                    maior = letras[l];
                }
            }
        }

        long soma = 0;
        for(auto s: letras){
            if(s.second == maior){
                soma += s.second * m;
            }
            else{
                soma += s.second * n;
            }
        }

        cout << "Case " << (i + 1) << ": ";
        cout << soma << "\n";
        letras.clear();
    }
}