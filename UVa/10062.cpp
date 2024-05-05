#include<bits/stdc++.h>
using namespace std;

string s;
vector<pair<int, int>> listagem; // freq, quant

bool ordenar (const pair<int,int>& i, const pair<int,int>& j) { 
    if(i.second < j.second){
        return true;
    }
    else if(i.second > j.second){
        return false;
    }
    else{
        if(i.first > j.first){
            return true;
        }
        else{
            return false;
        }
    }
}

int main(){ // Tell me the frequencies!
    listagem.assign(300, make_pair(0, 0));
    int cont = 0;
    while(getline(cin, s)){
        if(cont > 0){
            cout << "\n";
        }
        for(int i = 0; i < 300; i++){
            listagem[i].first = i;
            listagem[i].second = 0;
        }
        for(int i = 0; i < s.size(); i++){
           listagem[s[i]].second++;
        }
        sort(listagem.begin(), listagem.end(), ordenar);
        for(int i = 0; i < 300; i++){
            if(listagem[i].second > 0){
                cout << listagem[i].first << " " << listagem[i].second << "\n";
            }
        }
        cont++;
    }
}