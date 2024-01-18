#include<bits/stdc++.h>
using namespace std;

int money [5] = {1, 5, 10, 20, 50};

bool conseguePagar(int64_t troco, int64_t nC []){     
    for(int j = 4; j >= 0; j--){
        while(nC[j] > 0 && troco >= money[j]){
            nC[j]--;
            troco -= money[j];
        }
    }
    if(troco != 0){
        return false;
    }
    return true;
}

int main(){ // Queue (A)
    int n;
    cin >> n;
    int64_t notasCaixa[5] = {0, 0, 0, 0, 0};
    int64_t caixa = 0, v, note, vp;
    string res = "yes";
    for(int i = 0; i < n; i++){
        cin >> v;
        vp = 0;
        int notes [5];
        for(int j = 0; j < 5; j++){
            cin >> notes[j];
        }
        for(int j = 4; j >= 0; j--){
            note = notes[j];
            while(note != 0 && vp < v){
                vp += money[j];
                note--;
                notasCaixa[j]++;
            }
        }
        int64_t troco = vp - v;
        if(troco > caixa || !conseguePagar(troco, notasCaixa)){
            res = "no";
        }
        else{
            caixa += v - troco;
        }
    }
    cout << res << "\n";
}