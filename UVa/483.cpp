#include<bits/stdc++.h>
using namespace std;

int main(){ // Word Scramble
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    string f;
    while(getline(cin, f)){
        string aux = "";
        for(int i = 0; i < f.size(); i++){
            if(f[i] != ' '){
                aux += f[i];
            }
            else{
                for(int j = aux.size() - 1; j >= 0; j--){
                    cout << aux[j];
                }
                cout << " ";
                aux = "";
            }
        }
        if(aux != ""){
            for(int j = aux.size() - 1; j >= 0; j--){
                cout << aux[j];
            }
        }
        cout << "\n";
    }
}