#include<iostream>
using namespace std;

int main(){ // Vestibular
    int questoes, i;
    string gab;
    string aluno;
    int ponto = 0;

    cin >> questoes;
    cin >> gab;
    cin >> aluno;

    for(i = 0; i < questoes; i++){
        if(gab[i] == aluno[i]){
            ponto++;
        }
    }

    cout << ponto << endl;

    return 0;
}