#include<bits/stdc++.h>
using namespace std;

int main(){ // Pares entre Cinco Números
    int x, cont = 0;
    for(int i = 0; i < 5; i++){
        cin >> x;
        if(x % 2 == 0){
            cont++;
        }
    }
    cout << cont << " valores pares" << "\n";
}