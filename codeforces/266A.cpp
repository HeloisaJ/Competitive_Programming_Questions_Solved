#include<iostream>
#include<string>
using namespace std;

int main(){ // Stones on the Table
	int n;
	string s;
	cin >> n >> s;
	int cont = 0;
	int i;
	for(i = 0; i < n - 1; i++){
		if(s[i] == s[i+1]){
			cont++;
		}
	}
	cout << cont << endl;
	return 0;
}
