#include<bits/stdc++.h>
using namespace std;

int main(){ // Mischievous Children
    int n;
    cin >> n;
    string x;
    for(int i = 1; i <= n; i++){
        cin >> x;
        vector<char> arm;
        int cont[x.size()];
        for(int j = 0; j < x.size(); j++){
            cont[j] = 0;
        }
        bool rep = false;
        for(int j = 0; j < x.size(); j++){
            for(int k = 0; k < arm.size(); k++){
                if(x[j] == arm[k]){
                    cont[k]++;
                    rep = true;
                }
            }
            if(!rep){
                arm.push_back(x[j]);
            }
            rep = false;
        }
        unsigned long long res = 1;
        for(int j = x.size(); j > 1; j--){
            res = res * j;
        }
        for(int j = 0; j < x.size(); j++){
            if(cont[j] != 0){
                for(int k = cont[j] + 1; k > 1; k--){
                    res = res/k;
                }
            }
        }
        cout << "Data set " << i << ": " << res << endl;
    }
    return 0;
}