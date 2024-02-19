#include<bits/stdc++.h>
using namespace std;

vector<int> semiPrimes;
bool dp[11234];
vector<int> primes;

bool isPrime(int n){
    int r = sqrt(n);
    for(int i = 2; i <= r; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

void inicializar(){
    for(int i = 2; i <= 97; i++){
        if(isPrime(i)){
            primes.push_back(i);
        }
    }
    int val;
    for(int i = 0; i < primes.size(); i++){
        for(int j = 0; j < primes.size(); j++){
            val = primes[i] * primes[j];
            if(i != j && val <= 200){
                semiPrimes.push_back(val);
                dp[val] = true;
            }
        }
    }
    sort(semiPrimes.begin(), semiPrimes.end());
}

int main(){ // Chef and Semi-Primes
    memset(dp, false, sizeof(dp));
    inicializar();
    int t, n;
    cin >> t;
    bool resp;
    for(int i = 0; i < t; i++){
        resp = false;
        cin >> n;
        for(int j = 0; j < semiPrimes.size(); j++){
            if(semiPrimes[j] > n){
                break;
            }
            else{
                if(dp[n - semiPrimes[j]]){
                    resp = true;
                    break;
                }
            }
        }
        if(resp){
            cout << "YES" << "\n";
        }
        else{
            cout << "NO" << "\n";
        }
    }
}