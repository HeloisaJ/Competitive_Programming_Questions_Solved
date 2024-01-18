#include<bits/stdc++.h>
using namespace std;

vector<int> specim;

pair<pair<int, int>, pair<int, int>> maiorNum(int s, bool apagado[]){
    int maior = 0, posM;
    for(int i = 0; i < s; i++){
        if(specim[i] > maior && !apagado[i]){
            maior = specim[i];
            posM = i;
        }
    }
    apagado[posM] = true;
    return make_pair(make_pair(posM, -1), make_pair(maior, -1));
}

pair<pair<int, int>, pair<int, int>> maiorEMenor(int s, bool apagado[]){
    int maior = 0, menor = 1001, posM, posm;
    for(int i = 0; i < s; i++){
        if(specim[i] > maior && !apagado[i]){
            maior = specim[i];
            posM = i;
        }
        if(specim[i] < menor && !apagado[i]){
            menor = specim[i];
            posm = i;
        }
    }
    apagado[posM] = true;
    apagado[posm] = true;
    if(posM < posm){
        return make_pair(make_pair(posM, posm), make_pair(maior, menor));
    }
    else{
        return make_pair(make_pair(posm, posM), make_pair(menor, maior));
    }
}

int main(){ // Station Balance
    int c, s, spc, sozinho, cont = 1;
    double media, soma, total;
    while(cin >> c >> s){
        vector<pair<pair<int, int>, pair<int, int>>> chambers;
        bool apagado [s];
        total = 0;
        soma = 0;
        for(int i = 0; i < s; i++){
            cin >> spc;
            specim.push_back(spc);
            soma += spc;
            apagado[i] = false;
        }
        media = soma/c;
        sozinho = c * 2 - s;
        if(sozinho > s){
            sozinho = s;
        }
        for(int i = 0; i < sozinho; i++){
            chambers.push_back(maiorNum(s, apagado));
            total += abs(chambers[chambers.size() - 1].second.first - media);
        }
        if(specim.size() - sozinho > 0){
            for(int i = 0; i < specim.size() - sozinho; i+=2){
                chambers.push_back(maiorEMenor(s, apagado));
                total += abs(chambers[chambers.size() - 1].second.first + chambers[chambers.size() - 1].second.second - media);
            }
        }
        sort(chambers.begin(), chambers.end());
        cout << "Set #" << cont << "\n";
        for(int i = 0; i < chambers.size(); i++){
            cout << " " << i << ": ";
            if(chambers[i].first.second == -1){
                cout << chambers[i].second.first << "\n";
            }
            else{
                cout << chambers[i].second.first << " " << chambers[i].second.second << "\n";
            }
        }
        if(chambers.size() < c){
            for(int i = chambers.size(); i < c; i++){
                cout << " " << i << ":\n";
                total += abs(0 - media);
            }
        }
        printf("IMBALANCE = %.5f\n", total);
        cont++; 
        specim.clear();
        cout << "\n";
    }
}