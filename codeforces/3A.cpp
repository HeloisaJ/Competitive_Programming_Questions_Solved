#include<bits/stdc++.h>
using namespace std;

#define MAX 8

int sj, tj, si, ti;
char sc, tc;
vector<string> resp;

void calculo(){
    while(si != ti || sj != tj){
        if(si > ti){
            si--;
            if(sj == tj){
                resp.push_back("U");
            }
            else if(sj > tj){
                sj--;
                resp.push_back("LU");
            }
            else{
                sj++;
                resp.push_back("RU");
            }
        }
        else if(si < ti){
            si++;
            if(sj == tj){
                resp.push_back("D");
            }
            else if(sj > tj){
                sj--;
                resp.push_back("LD");
            }
            else{
                sj++;
                resp.push_back("RD");
            }
        }
        else{
            if(sj > tj){
                sj--;
                resp.push_back("L");
            }
            else{
                sj++;
                resp.push_back("R");
            }
        }
    }
}

int main(){ // Shortest path of the king
    cin >> sc >> si >> tc >> ti;
    si = MAX - si;
    ti = MAX - ti;
    sj = sc - 97;
    tj = tc - 97;

    calculo();
    cout << resp.size() << "\n";

    for(int i = 0; i < resp.size(); i++){
        cout << resp[i] << "\n";
    }
}