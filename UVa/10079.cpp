#include<bits/stdc++.h>
using namespace std;

int64_t a[212345678];

int main(){ // Pizza Cutting
    long n;
    a[0] = 1;
    a[1] = 2;
    unsigned long preenchido = 1;
    while(cin >> n && n >= 0){
        while(n > preenchido){
            a[preenchido + 1] = a[preenchido] + preenchido + 1;
            preenchido++;
        }
        cout << a[n] << "\n";
    }
}