#include<bits/stdc++.h>
using namespace std;

int main(){ // An Interesting Game
    int t;
    cin >> t;
    for(int z = 1; z <= t; z++){
        int n, k, x;
        long res = 0;
        cin >> n >> k >> x;
        for(int i = 1; i <= n; i++){
            if(i < x || i >= k + x){
                res += i;
            }
        }
        cout << "Case " << z << ": " << res << endl;
    }
}