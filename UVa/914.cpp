#include<bits/stdc++.h>
using namespace std;

long primos[1123456];
long subtracao[1123456];
long maior, pos;

bool isPrime(long x){
    long raiz = sqrt(x);
    for(int i = 2; i <= raiz; i++){
        if(x % i == 0){
            return false;
        }
    }
    return true;
}

void ajustarLimite(long u){
    for(int i = maior + 1; i <= u; i++){
        if(isPrime(i)){
            primos[pos] = i;
            subtracao[pos - 1] = i - primos[pos - 1];
            pos++;
        }
    }
    maior = u;
}

int posMenorPrimo(long l, long u){
    for(int i = 0; i < pos; i++){
        if(primos[i] >= l && primos[i] <= u){
            return i;
        }
    }
    return -1;
}

int posMaiorPrimo(long u, long l){
    for(int i = pos - 1; i >= 0; i--){
        if(primos[i] <= u && primos[i] >= l){
            return i;
        }
    }
    return -1;
}

int main(){ // Jumping Champion
    int t;
    cin >> t;
    long u, l;
    maior = 2;
    primos[0] = 2;
    pos = 1;
    long posI, posF;
    for(int k = 0; k < t; k++){
        cin >> l >> u;
        if(u > maior){
            ajustarLimite(u);
            posF = pos - 2;
        }
        else{
            posF = posMaiorPrimo(u, l) - 1;
        }
        if(l > 2){
            posI = posMenorPrimo(l, u);
        }
        else{
            posI = 0;
        }
        if(posI < 0 || posF < 0 || posF - posI == 1){
            cout << "No jumping champion" << "\n";
        }
        else{
            map<long, long> diferenca;
            long maiorQuantApareceu = 0, numQMaisApareceu = -1;
            for(int i = posI; i <= posF; i++){
                if(diferenca.find(subtracao[i]) == diferenca.end()){
                    diferenca.insert(make_pair(subtracao[i], 1));
                }
                else{
                    diferenca[subtracao[i]] = diferenca[subtracao[i]] + 1;
                }
                if(diferenca[subtracao[i]] > maiorQuantApareceu){
                    maiorQuantApareceu = diferenca[subtracao[i]];
                }
            }
            bool champ = true;
            for(auto &x: diferenca){
                if(x.second == maiorQuantApareceu){
                    if(numQMaisApareceu == -1){
                        numQMaisApareceu = x.first;
                    }
                    else{
                        cout << "No jumping champion" << "\n";
                        champ = false;
                        break;
                    }
                }
            }
            if(champ){
                cout << "The jumping champion is " << numQMaisApareceu << "\n";
            }
        }
    }
}