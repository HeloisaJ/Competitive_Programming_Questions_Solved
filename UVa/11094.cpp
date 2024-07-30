#include<bits/stdc++.h>
using namespace std;

char letras[2];
char matriz[21][21];
bool visited[21][21];
int continent, cont, maior, n, m, quant, x, y;
int dx[]{1, 0, -1, 0}, dy[]{0, 1, 0, -1};
bool valido;

bool verificar(int xi){
    if(xi >= 0 && xi < m){
        return true;
    }
    return false;
}

void calculoDfs(int i, int j){
    visited[i][j] = true;
    quant++;
    if(x == i && y == j){
        valido = false;
    }

    for(int k = 0; k < 4; k++){
	    int xi = i + dx[k], yi = j + dy[k];

        yi = (yi + n) % n;

	    if(verificar(xi) && !visited[xi][yi] && matriz[xi][yi] == letras[continent]){ 
		    calculoDfs(xi, yi);
        }
    }
}

int main(){ // Continents
    while(cin >> m >> n){
        cont = -1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cin >> matriz[i][j];
                visited[i][j] = false;

                if(cont == -1 || (cont == 0 && matriz[i][j] != letras[cont])){
                    cont++;
                    letras[cont] = matriz[i][j];
                }
            }
        }

        cin >> x >> y;
        if(matriz[x][y] == letras[0]){
            continent = 0;
        }
        else{
            continent = 1;
        }

        maior = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matriz[i][j] == letras[continent] && !visited[i][j]){
                    quant = 0;
                    valido = true;
                    calculoDfs(i, j);

                    if(valido && quant > maior){
                        maior = quant;
                    }
                }
            }
        }

        cout << maior << "\n";
    }
}