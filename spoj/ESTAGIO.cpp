#include<bits/stdc++.h>
using namespace std;

const int MAX_ALUNOS = 1000;

int main() // Estágio
{
  int i, indice_melhor, n;
  int turma=1;
  struct{
    int codigo, media;
  } alunos[MAX_ALUNOS];
  // le numero de alunos da primeira turma
  cin >> n;
  while (n > 0){
      // le dados dos alunos
      for (i = 0; i < n; i++)
         cin >> alunos[i].codigo >> alunos[i].media;
      // procura aluno de maior media
      indice_melhor = 0;
      vector<int> melhores;
      for (i = 0; i < n; i++)
         if (alunos[i].media > alunos[indice_melhor].media){
             indice_melhor = i;
             melhores.clear();
             melhores.push_back(i);
         }
         else if(alunos[i].media == alunos[indice_melhor].media){
            melhores.push_back(i);
         }
      // escreve resposta
      cout << "Turma " << turma++ << "\n";
      for(int i = 0; i < melhores.size(); i++){
        if(i != melhores.size() - 1){
            cout << alunos[melhores[i]].codigo << " ";
        }
        else{
            cout << alunos[melhores[i]].codigo;
        }
      }
      cout << "\n\n";
      // le numero de alunos da proxima turma
      cin >> n;
    }
  return 0;
}