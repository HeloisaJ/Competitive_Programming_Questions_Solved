#include<bits/stdc++.h>
using namespace std;

vector<int> ba;
vector<int> ab;
int contA, contB;

void exibir(int val, vector<int> x){
    for(int i = val; i < x.size(); i += 2){
        cout << x[i] << " " << x[i + 1] << "\n";
    }
}

int main(){ // Swap Letters
    string s, t;
    int n;
    cin >> n;
    cin >> s >> t;
    contA = 0;
    contB = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'a'){
            contA++;
        }
        else{
            contB++;
        }
        if(t[i] == 'a'){
            contA++;
        }
        else{
            contB++;
        }
        if(s[i] == 'a' && t[i] == 'b'){
            ab.push_back(i + 1);
        }
        if(s[i] == 'b' && t[i] == 'a'){
            ba.push_back(i + 1);
        }
    }
    if(contA % 2 != 0 || contB % 2 != 0){
        cout << -1 << "\n";
    }
    else if(contA == 0 || contB == 0 || (ab.size() == 0 && ba.size() == 0)){
        cout << 0 << "\n";
    }
    else{
        bool abPar = false, baPar = false;
        if(ab.size() % 2 == 0) abPar = true;
        if(ba.size() % 2 == 0) baPar = true;
        if(abPar != baPar){
            cout << -1 << "\n";
        }
        else{
            int minimo = min(ab.size(), ba.size()), i = 0;
            if(!abPar && !baPar){
                cout << ab.size() / 2 + ba.size()/2 + 2 << "\n";
                cout << ab[0] << " " << ab[0] << "\n";
                cout << ab[0] << " " << ba[0] << "\n";
                i = 1;
            }
            else{
                cout << ab.size() / 2 + ba.size()/2 << "\n";
            }
            exibir(i, ba);
            exibir(i, ab);
        }
    }
}