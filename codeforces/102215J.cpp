#include<bits/stdc++.h>
using namespace std;
#define MAX 512345

long long menor[MAX];
long long soma[MAX];
long long somaMenor[MAX];
long long vitorias, n;

void busca(long long i){
    long long ini = 0, fim = n, meio;
    while(ini <= fim){
        meio = (ini + fim)/2;
        if(meio < 0 || meio >= n){
            return;
        }
        if(soma[i] >= menor[meio]){
            vitorias = meio + 1;
            if(somaMenor[i] <= menor[meio]){
                vitorias--;
            }
            ini = meio + 1;
        }
        else{
            fim = meio - 1;
        }
    }
}

int main(){ // The Power of the Dark Side - 2
    cin.tie(0);
	ios_base::sync_with_stdio(0);
    cin >> n;
    long long a, b, c, sa, sb, sc;
    for(long long i = 0; i < n; i++){
        cin >> a >> b >> c;
        soma[i] = a + b + c;
        sa = b + c + 2;
        sb = a + c + 2;
        sc = a + b + 2;
        if(sa <= sb && sa <= sc){
            menor[i] = sa;
        }
        else if(sb <= sa && sb <= sc){
            menor[i] = sb;
        }
        else{
            menor[i] = sc;
        }
        somaMenor[i] = menor[i];
    }
    sort(menor, menor + n);
    for(long long i = 0; i < n; i++){
        vitorias = 0;
        busca(i);
        cout << vitorias;
        if(i != n - 1){
            cout << " ";
        }
    }
    cout << "\n";
}