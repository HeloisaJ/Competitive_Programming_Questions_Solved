#include<bits/stdc++.h>
using namespace std;

int tamS = 6;

int main(){ // Proteja sua senha
    int n, teste = 1;
    while(cin >> n && n != 0){
        if(teste > 1){
            cout << "\n";
        }
        int pont [tamS][10];
        for(int j = 0; j < tamS; j++){
            for(int u = 0; u < 10; u++){
                pont[j][u] = 0;
            }
        }
        int x1, x2; 
        char senha;
        map<char, pair<int, int>> letras;
        for(int i = 0; i < n; i++){
            letras.clear();
            for(int j = 0; j < 5; j++){
                cin >> x1 >> x2;
                letras.insert(make_pair('A' + j, make_pair(x1, x2)));
            }
            
            for(int j = 0; j < tamS; j++){
                cin >> senha;
                pont[j][letras[senha].first]++;
                pont[j][letras[senha].second]++;
            }
        }
        cout << "Teste " << teste << "\n";
        for(int i = 0; i < tamS; i++){
            int maior = 0, x;
            for(int u = 0; u < 10; u++){
                if(pont[i][u] > maior){
                    maior = pont[i][u];
                    x = u;
                }
            }
            cout << x;
            if(i < tamS - 1){
                cout << " ";
            } 
        }
        cout << "\n";
        teste++;
    }
}