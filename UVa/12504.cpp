#include<bits/stdc++.h>
using namespace std;

void exibir(set<string> s){
    int cont = 0;
    for(string x: s){
        cout << x;
        cont++;
        if(cont != s.size()){
            cout << ",";
        }
    }
}

void c(string x, map<string, string> &m){
    pair<string, string> p;
    bool chave = true;
    p.first = "";
    p.second = "";

    for(int i = 1; i < x.size() - 1; i++){
        if(x[i] == ':'){
            chave = false;
        }
        else if(x[i] == ','){
            chave = true;
            m.insert(make_pair(p.first, p.second));
            p.first = "";
            p.second = "";
        }
        else{
            if(chave){
                p.first += x[i];
            }
            else{
                p.second += x[i];
            }
        }
    }
    if(p.first != ""){
        m.insert(make_pair(p.first, p.second));
    }
}

int main(){ // Updating a Dictionary
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;

    for(int k = 0; k < t; k++){
        if(k > 0){
            cout << "\n";
        }
        string x, y;
        map<string, string> novo;
        map<string, string> velho;
        set<string> mais, menos, mudou;
        //getline(cin, x);
        //getline(cin, y);
        
        cin >> x >> y;

        c(x, velho);
        c(y, novo);

        for(auto f: novo){
            if(velho.find(f.first) == velho.end()){
                mais.insert(f.first);
            }
            else{
                if(velho[f.first] != f.second){
                    mudou.insert(f.first);
                }
            }
        }

        if(mais.size() > 0){
            cout << '+';
            exibir(mais);
            cout << "\n";
        }

        for(auto f: velho){
            if(novo.find(f.first) == novo.end()){
                menos.insert(f.first);
            }
        }

        if(menos.size() > 0){
            cout << '-';
            exibir(menos);
            cout << "\n";
        }

        if(mudou.size() > 0){
            cout << '*';
            exibir(mudou);
            cout << "\n";
        }

        if(menos.size() == 0 && mais.size() == 0 && mudou.size() == 0){
            cout << "No changes" << "\n";
        }
    }
    cout << "\n";
}