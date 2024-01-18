#include<iostream>
using namespace std;

int main(){ // Bear and Big Brother
	int l, b, cont = 1;
	cin >> l >> b;

	while(l * 3 <= b * 2){
		l = l * 3;
		b = b * 2;
		cont++;
	}

	cout << cont;

	return 0;
}
