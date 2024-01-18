#include<bits/stdc++.h>
using namespace std;

int n;
long l;

int main(){ // Vanya and Lanterns
	cin >> n >> l;	
	int lant[n];
	for(int i = 0; i < n; i++){
		cin >> lant[i];
	}
	sort(lant, lant + n);
	double raio = lant[0];
	if(raio == 0 && n > 1){
		raio = (lant[1] - lant[0])/2.0;
	}
	double dist = raio;
	for(int i = 0; i < n - 1; i++){
		raio = lant[i + 1] - lant[i] - raio;
		if(raio > (lant[i + 1] - lant[i])/2.0){
			raio = (lant[i + 1] - lant[i])/2.0;
		}
		if(dist < raio){
			dist = raio;
		}
		else if(raio < 0){
			raio = -raio;
		}
	}
	if(l - lant[n - 1] > dist){
		dist = l - lant[n - 1];
	}
	printf("%.10f", dist);
}
