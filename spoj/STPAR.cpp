#include<bits/stdc++.h>
using namespace std;

stack<int> rua;
int c;

void func(){
    while(!rua.empty() && rua.top() == c){
        rua.pop();
        c++;
    }
}

int main(){ // Street Parade
    int n;
    while(cin >> n && n != 0){
        int t;
        c = 1;
        for(int i = 0; i < n; i++){
            cin >> t;
            if(t == c){
                c++;
            }
            else{
                if(!rua.empty()){
                    if(rua.top() != c){
                        rua.push(t);
                    }
                    else{
                        func();
                    }
                }
                else{
                    rua.push(t);
                }
            }
            func();
        }
        func();
        if(!rua.empty()){
            cout << "no" << "\n";
        }
        else{
            cout << "yes" << "\n";
        }
        while(!rua.empty()){
            rua.pop();
        }
    }
}