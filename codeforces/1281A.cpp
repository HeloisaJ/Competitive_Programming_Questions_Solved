#include<iostream>
using namespace std;

int main(){ // Suffix Three
	int t;
	cin >> t;
	string word;
	for(int i = 0; i < t; i++){
		cin >> word;
		if(word[word.size() - 1] == 'o'){
			cout << "FILIPINO" << endl;
		}
		else if(word[word.size() - 1] == 'u'){
			cout << "JAPANESE" << endl;
		}
		else{
			cout << "KOREAN" << endl;
		}
	}
	return 0;
}
