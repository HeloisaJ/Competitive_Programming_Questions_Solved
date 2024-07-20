#include<iostream>
using namespace std;

int main(){ // Train Swapping
    int N;
    int swaps = 0;
    cin >> N;
    for(int i = 0; i < N; i++){
        int L;
        cin >> L;
        int train[L];
        for(int j = 0; j < L; j++){
            cin >> train[j];
        }
        for(int k = 0; k < L; k++){
            for(int j = 0; j < L; j++){
                if(j + 1 != L){
                    while(train[j] > train[j + 1]){
                        int aux = train[j];
                        train[j] = train[j + 1];
                        train[j + 1] = aux;
                        swaps++;
                    }
                }
            }   
        }
        cout << "Optimal train swapping takes " << swaps << " swaps." << endl;
        swaps = 0;
    }

    return 0;
}