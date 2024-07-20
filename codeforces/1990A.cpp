#include<bits/stdc++.h>
using namespace std;

int a[52];

int main(){ // Submission Bait
    int t, n;
    cin >> t;
    for(int k = 0; k < t; k++){
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        bool yes = false;
        sort(a, a + n);
        int maior, pos = n - 1, soma = 0;

        while(pos >= 0){
            maior = a[pos];
            pair<int*, int*> range = equal_range(a, a + n, maior);

            soma += range.second - range.first;

            if(soma % 2 != 0){
                yes = true;
                break;
            }

            pos = range.first - a;
            pos--;
        }

        if(yes){
            cout << "YES";
        }
        else{
            cout << "NO";
        }

        cout << "\n";
    }
}