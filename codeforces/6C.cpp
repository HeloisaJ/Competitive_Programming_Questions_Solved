#include<bits/stdc++.h>
using namespace std;

int tempos[112345];

int main(){ // Alice, Bob and Chocolate
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> tempos[i];
    }
    int A = 0, B = 0, posA = 0, posB = n - 1;
    unsigned long long tA = 0, tB = 0;
    while(A + B != n){
        if(tA <= tB){
            tA += tempos[posA];
            posA++;
            A++;
        }
        else{
            tB += tempos[posB];
            posB--;
            B++;
        }
    }
    cout << A << " " << B << "\n";
}