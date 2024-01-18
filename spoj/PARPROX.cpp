#include<bits/stdc++.h>
using namespace std;

pair<int, int> pontos[1123]; // x = first, y = second
int n;

int main(){ // Pontos
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> pontos[i].first >> pontos[i].second;
	}
	double menor = 8000000, dist;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			dist = sqrt(pow(pontos[i].first - pontos[j].first, 2.0) + pow(pontos[i].second - pontos[j].second, 2.0));
			if(dist < menor){
				menor = dist;
			}
		}
	}
	printf("%.3f", menor);
}
