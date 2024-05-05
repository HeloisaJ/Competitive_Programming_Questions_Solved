#include<bits/stdc++.h>
using namespace std;

int main(){ // Tipos de Triângulos
    double valores[3];
    cin >> valores[0] >> valores[1] >> valores[2];
    sort(valores, valores + 3);
    double a, b, c, a2, b2, c2;
    a = valores[2];
    b = valores[1];
    c = valores[0];
    a2 = a * a;
    b2 = b * b;
    c2 = c * c;
    if(a >= b + c){
        cout << "NAO FORMA TRIANGULO" << "\n";
    }
    else{
        if(a2 == b2 + c2){
            cout << "TRIANGULO RETANGULO" << "\n";
        }
        if(a2 > b2 + c2){
            cout << "TRIANGULO OBTUSANGULO" << "\n";
        }
        if(a2 < b2 + c2){
            cout << "TRIANGULO ACUTANGULO" << "\n";
        }
        if(a == b && b == c){
            cout << "TRIANGULO EQUILATERO" << "\n";
        }
        if((a == b && b != c) || (b == c && a != b) || (c == a && b != a)){
            cout << "TRIANGULO ISOSCELES" << "\n";
        }
    }
}