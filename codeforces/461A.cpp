#include<bits/stdc++.h>
using namespace std;

int main(){ // Appleman and Toastman
    int n;
    cin >> n;
    unsigned long long sum = 0, m, total = 0;
    long num [n];
    for(int i = 0; i < n; i++){
        cin >> m;
        sum += m;
        num[i] = m;
    }
    int i = 0;
    sort(num, num + n);
    total += sum;
    while(i < n - 1){
        total += sum;
        m = num[i];
        sum -= m;
        i++;
    }
    cout << total << "\n";
}