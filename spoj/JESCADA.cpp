#include<iostream>
using namespace std;

int main(){ // Escada
	int p;
	int ant, dep;
	int tot = 0;
	cin >> p;
	cin >> ant;
	for(int i = 1; i < p; i++){
		cin >> dep;
		if(dep - ant < 10){
			tot += dep - ant;
		}
		else{
			tot+= 10;
		}
		ant = dep;
	}
	if(p > 0){
		tot += 10;
	}
	cout << tot << endl;
	return 0;
}
