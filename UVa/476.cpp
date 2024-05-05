#include<bits/stdc++.h>
using namespace std;

vector<vector<float>> poligono;

int main(){ // Points in Figures: Rectangles
    char s;
    float x1, y1, x2, y2;
    while(cin >> s && s != '*'){
        poligono.push_back(vector<float>());
        cin >> x1 >> y1 >> x2 >> y2;
        poligono[poligono.size() - 1].push_back(x1);
        poligono[poligono.size() - 1].push_back(y1);
        poligono[poligono.size() - 1].push_back(x2);
        poligono[poligono.size() - 1].push_back(y2);
    }
    float x, y;
    string sx, sy;
    int cont = 0;
    bool dentro;
    while(cin >> sx >> sy){
        bool finalizar = true;
        for(int i = 0; i < sx.size(); i++){
            if(sx[i] == '.'){
                continue;
            }
            else if(sx[i] != '9'){
                finalizar = false;
                break;
            }
        }
        if(sx.size() == 6 && finalizar){
            break;
        }
        x = stof(sx);
        y = stof(sy);
        cont++;
        dentro = false;
        for(int i = 0; i < poligono.size(); i++){
            if(y < poligono[i][1] && y > poligono[i][3] && x > poligono[i][0] && x < poligono[i][2]){
                dentro = true;
                cout << "Point " << cont << " is contained in figure " << (i + 1) << "\n";
            }
        }
        if(!dentro){
            cout << "Point " << cont << " is not contained in any figure" << "\n";
        }
    }
}