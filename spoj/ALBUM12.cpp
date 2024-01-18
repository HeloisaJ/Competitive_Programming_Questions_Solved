#include<bits/stdc++.h>
using namespace std;

int main(){ // Álbum de Fotos
	int x, y, l1, h1, l2, h2;
	char resp = 'N';
	cin >> x >> y >> l1 >> h1 >> l2 >> h2;

	if(l1 + l2 <= x && h1 <= y && h2 <= y){
		resp = 'S';
	}
	else if(h1 + h2 <= x && l1 <= y && l2 <= y){
		resp = 'S';
	}
	else if(h1 + h2 <= y && l1 <= x && l2 <= x){
		resp = 'S';
	}
	else if(l1 + l2 <= y && h1 <= x && h2 <= x){
		resp = 'S';
	}
	else if(l1 + h2 <= x && l2 <= y && h1 <= y){
		resp = 'S';
	}
	else if(l2 + h1 <= x && l1 <= y && h2 <= y){
		resp = 'S';
	}
	else if(l1 + h2 <= y && l2 <= x && h1 <= x){
		resp = 'S';
	}
	else if(l2 + h1 <= y && l1 <= x && h2 <= x){
		resp = 'S';
	}

	cout << resp << endl;

	return 0;
}
