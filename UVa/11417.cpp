#include<bits/stdc++.h>
using namespace std;

int main(){ // GCD
    int n;
    while(cin >> n && n != 0){
        int G=0;
        for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
        {
            G += __gcd(i,j);
        }
        cout << G << endl;
    }
}