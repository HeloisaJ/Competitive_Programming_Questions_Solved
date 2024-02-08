#include<bits/stdc++.h>
using namespace std;

int ultimoNumero;
int quantDigitPrime [11234567];
vector<int> primos;

bool isPrime(int num){
    int raiz = sqrt(num);
    for(int i = 2; i <= raiz; i++){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}

int somaDigitos(int num){
    int soma = 0;
    while(num > 0){
        soma += num % 10;
        num /= 10;
    }
    return soma;
}

void calculo(int maximo){
    int soma;
    for(int i = ultimoNumero + 1; i <= maximo; i++){
        if(isPrime(i)){
            primos.push_back(i);
            soma = somaDigitos(i);
            if(binary_search(primos.begin(), primos.end(), soma)){
                quantDigitPrime[i] = quantDigitPrime[i - 1] + 1;
            }
            else{
                quantDigitPrime[i] = quantDigitPrime[i - 1];
            }
        }
        else{
            quantDigitPrime[i] = quantDigitPrime[i - 1];
        }
    }
}

int main(){ // Digit Primes
    int n, maximo, minimo;
    scanf("%d", &n);
    ultimoNumero = 1;
    quantDigitPrime[0] = 0;
    quantDigitPrime[1] = 0;
    for(int k = 0; k < n; k++){
        scanf("%d%d", &minimo, &maximo);
        if(maximo > ultimoNumero){
            calculo(maximo);
            ultimoNumero = maximo;
        }
        int sub = quantDigitPrime[maximo] - quantDigitPrime[minimo - 1];
        printf("%d\n", sub);
    }
}