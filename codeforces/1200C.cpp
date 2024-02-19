#include<bits/stdc++.h>
using namespace std;

unsigned long long n, m, nDiv, c1, p1, c2, p2, esp1, esp2;

void resposta(unsigned long long v1, unsigned long long v2){
    if((p1 - 1)/v1 == (p2 - 1)/v2){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
}

int main(){ // Round Corridor
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int q;
    cin >> n >> m;
    if(n % m == 0){
        nDiv = m;
    }
    else if(m % n == 0){
        nDiv = n;
    }
    else{
        nDiv = __gcd(n, m);
    }
    cin >> q;
    esp1 = n/nDiv;
    esp2 = m/nDiv;
    for(int i = 0; i < q; i++){
        cin >> c1 >> p1 >> c2 >> p2;
        if(nDiv == 1){
            cout << "YES\n";
        }
        else if(c1 != c2){
            if(c1 == 1){
                resposta(esp1, esp2);
            }
            else{
                resposta(esp2, esp1);
            }
        }
        else if(c1 == 1){
            resposta(esp1, esp1);
        }
        else{
            resposta(esp2, esp2);
        }
    }
}