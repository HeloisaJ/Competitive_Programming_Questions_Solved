#include<iostream>
#include<string>
using namespace std;

// Huaauhahhuahau

bool eVogal(string s, int pos){ 
	if(s[pos] == 'a' || s[pos] == 'e' || s[pos] == 'i' || s[pos] == 'o' || s[pos] == 'u'){
		return true;
	}
	return false;
}

int main(){
	string s;
	char res = 'S';
	int pos1 = 0;
	cin >> s;
	int pos2 = s.length() - 1;

	while(pos1 != s.length() && pos2 != 0){
		if(eVogal(s, pos1)){
			if(eVogal(s, pos2)){
				if(s[pos1] != s[pos2]){
					res = 'N';
					break;
				}
				else{
					pos1++;
					pos2--;
				}
			}
			else{
				pos2--;
			}
		}
		else{
			pos1++;
		}
	}

	cout << res << endl;

	return 0;
}
