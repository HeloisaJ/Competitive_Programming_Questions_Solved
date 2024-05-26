#include<bits/stdc++.h>
using namespace std;

#define MAX 7123456

int n;
long long a[MAX];
long long b[MAX];
long long c[MAX];
long long d[MAX];
vector<long long> ab;
vector<long long> cd;

vector<long long> combinacoes(long long x[], long long y[]){
    vector<long long> valores;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            valores.push_back(x[i] + y[j]);
        }
    }
    return valores;
}

int main(){ // 4 values whose sum is 0
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    ab = combinacoes(a, b);
    cd = combinacoes(c, d);
    sort(ab.begin(), ab.end());
    sort(cd.begin(), cd.end());
    int pos, quant;
    long long cont = 0;
    for(int i = 0; i < ab.size(); i++){
        pos = (lower_bound(cd.begin(), cd.end(), -ab[i]) - cd.begin());
        quant = (upper_bound(cd.begin(), cd.end(), -ab[i]) - cd.begin());
        if(pos != ab.size() && ab[i] + cd[pos] == 0){
            cont += (quant - pos);
        }
    }
    cout << cont << "\n";
}