#include<bits/stdc++.h>
using namespace std;
 
long n, l, r, x, cont;
long a[20];
long dp[65890];
 
long menosSignificativo(long x){
    return ((x) & (-x));
}
 
void calculo(int i, int mask){
    int valMask = mask | (1 << i);
    if(valMask > (1 << n) - 1 || dp[valMask] != -1){
        return;
    }
    dp[valMask] = dp[mask] + a[i];
    if(dp[valMask] < l || __builtin_popcount(valMask) == 1){
        calculo(i + 1, valMask);
        calculo(i + 1, mask);
    }
    else if(dp[valMask] > r){
        return;
    }
    else{
        long m = menosSignificativo(valMask);
        if(m > 1){
            m = log2(m);
        }
        else{
            m--;
        }
        if(a[i] - a[m] >= x){
            cont++;
        }
        calculo(i + 1, valMask);
        calculo(i + 1, mask);
    }
}
 
int main(){ // Preparing Olympiad
    cin >> n >> l >> r >> x;
    cont = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    calculo(0, 0);
    cout << cont << "\n";
}