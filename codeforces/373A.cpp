#include<iostream>
#include<string>
using namespace std;

int main(){ // Collecting Beats is Fun
	string res = "YES";
	char board;
	int num[9] = {0,0,0,0,0,0,0,0,0};
	int i, j;
	int press;
	cin >> press;
	int conv;

	for(i = 0; i < 16; i++){
		cin >> board;
		if(board != '.'){
			if(board == '1'){
				num[0] += 1;
			}
			else if(board == '2'){
				num[1] += 1;
			}
			else if(board == '3'){
				num[2] += 1;
			}
			else if(board == '4'){
				num[3] += 1;
			}
			else if(board == '5'){
				num[4] += 1;
			}
			else if(board == '6'){
				num[5] += 1;
			}
			else if(board == '7'){
				num[6] += 1;
			}
			else if(board == '8'){
				num[7] += 1;
			}
			else if(board == '9'){
				num[8] += 1;
			}
		}
	}

	for(i = 0; i < 9; i++){
		if(num[i] > press * 2){
			res = "NO";
			break;
		}
	}

	cout << res << endl;

	return 0;
}
