#include<bits/stdc++.h>
using namespace std;

int n;
long t;

int main(){ // Books
	cin >> n >> t;
	int seq[n];
	for(int i = 0; i < n; i++){
		cin >> seq[i];
	}
	int start = 0, end = 0, books = 0, max = 0;
	long time = 0;
	while(start != n && books < n){
		time += seq[end];
		if(time <= t){
			books++;
		}
		else if(seq[end] > t){
			start = end + 1;
			books = 0;
			time = 0;
		}
		else{
			while(time > t && start != n && start <= end){
				time -= seq[start];
				start++;
				books--;
			}
			if(start <= end){
				books++;
			}
		}
		if(books > max){
			max = books;
		}
		end++;
		if(end == n){
			break;
		}
	}
	cout << max << endl;
}
