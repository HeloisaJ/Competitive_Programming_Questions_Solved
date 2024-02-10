#include<bits/stdc++.h>
using namespace std;

long t;
vector<long long> a;
long long n, v, maior;

int main(){ // Maximum Subset Sum
    cin >> t;
    for(long k = 0; k < t; k++){
        cin >> n >> v;
        a.assign(n, 0);
        a[0] = v;
        maior = v;
        for(long long i = 1; i < n; i++){
            cin >> v;
            a[i] = max(v, v + a[i - 1]);
            if(a[i] > maior){
                maior = a[i];
            }
        }
        cout << maior << "\n";
        a.clear();
    }
}