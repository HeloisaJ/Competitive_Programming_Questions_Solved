#include<iostream>
using namespace std;

int main(){ // Fuga com Helicóptero
	int H, P, F, D;
	cin >> H >> P >> F >> D;
	char res = 'S';
	if(D == -1){
		while(F != H){
			if(F == P){
				res = 'N';
				break;
			}
			else if(F < 0){
				F = 15;
			}
			else{
				F--;
			}
		}
	}
	else{
		while(F != H){
			if(F == P){
				res = 'N';
				break;
			}
			else if(F > 15){
				F = 0;
			}
			else{
				F++;
			}
		}

	}

	cout << res;
	return 0;
}
