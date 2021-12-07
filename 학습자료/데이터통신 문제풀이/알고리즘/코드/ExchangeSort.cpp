#include <iostream>

using namespace std;


void exchangeSort(int n, int S[]){
    int i, j;
    int temp;
    for(i = 0; i<n; i++){
        for(j = i+1; j<n; j++){
            if(S[j] < S[i]){
                temp = S[i];
                S[i] = S[j];
                S[j] = temp;
            } 
        }
    }
}
int main(){
    int S[] = {1,5,3,6,4,8,9,10,2,7};

    int n = 10;
    exchangeSort(n, S);
    for(int i = 0; i<n; i++){
        cout << S[i] << " ";
    }
}