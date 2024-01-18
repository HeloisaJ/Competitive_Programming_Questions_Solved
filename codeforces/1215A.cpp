#include<bits/stdc++.h>
using namespace std;

int func(int tot, int c, int n){
	int cont = 0;
	while(tot - c >= 0 && cont <= n){
		tot -= c;
		cont++;
	}
	return cont;
}

int CalcMax(int n, int c, int no, int co, int tot){
	int resp = 0;
	if(tot - n * c >= 0){
		tot -= n * c;
		if(tot != 0 && tot >= co){
			resp = n + func(tot, co, no);
		}
		else{
			resp = n;
		}
	}
	else{
		resp = func(tot, c, n);
	}
	return resp;
}

int CalcMin(int n, int c, int no, int co, int tot){
	tot = tot - n * (c - 1) - no * (co - 1);
	if(tot < 0){
		return 0;
	}
	return tot;
}

int main(){ // Yellow Cards
	int n1, n2, c1, c2, tot, maximo, minimo;
	cin >> n1 >> n2 >> c1 >> c2 >> tot;
	if(c1 > c2){
		minimo = CalcMin(n1, c1, n2, c2, tot);
		maximo = CalcMax(n2, c2, n1, c1, tot);
	}
	else{
		maximo = CalcMax(n1, c1, n2, c2, tot);
		minimo = CalcMin(n2, c2, n1, c1, tot);
	}
	cout << minimo << " " << maximo << endl;
}
