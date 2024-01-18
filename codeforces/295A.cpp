#include<bits/stdc++.h>
using namespace std;

int n, m, k;
const int tam = 100005;
int matriz[tam][3];
int64_t a[tam];
int64_t kArray[tam];
int64_t referencia[tam];

int main(){ // Greg and Array
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        referencia[i] = 0;
        kArray[i] = 0;
    }
    for(int i = 0; i < m; i++){
        cin >> matriz[i][0] >> matriz[i][1] >> matriz[i][2];
    }
    long long sum = 0;
    int inicio, fim;
    for(int i = 0; i < k; i++){
        cin >> inicio >> fim;
        kArray[inicio - 1] += 1;
        kArray[fim] -= 1;
    }
    for(int i = 0; i < m; i++){
        sum += kArray[i];
        referencia[matriz[i][0] - 1] += matriz[i][2] * sum;
        referencia[matriz[i][1]] -= matriz[i][2] * sum;
    }
    sum = 0;
    for(int i = 0; i < n; i++){
        sum += referencia[i];
        cout << a[i] + sum;
        if(i != n - 1){
            cout << " ";
        }
    }
    cout << "\n";
}