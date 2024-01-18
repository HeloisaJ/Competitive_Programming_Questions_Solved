#include<iostream>
using namespace std;

int main(){ // Logical Sequence 2
	int X, Y;
	cin >> X;
	cin >> Y;
	int cont = 1;
	int cont2 = 1;

	while(cont <= Y){
		if(cont2 > X){
            cont2 = 1;
            cout << cont;
			if(X > 1){
				cout << " ";
			}
		}
        else if(cont2 == X){
            cout << cont;
			cout << "\n";
        }
        else{
            cout << cont;
			cout << " ";
        }
		cont++;
        cont2++;
	}

	return 0;
}
