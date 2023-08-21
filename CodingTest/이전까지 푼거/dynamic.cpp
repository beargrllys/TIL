#include <iostream>
#include <cmath>

using namespace std;
#define Max 999;

int P[100][100] = {0};

void initArr(int (*Arry)[]){
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            Arry = 0;
        }
    }
}

void print(){
    for(int i=1; i<7; i++){
        for(int j=1; j<7; j++){
            cout << P[i][j] << " ";
        }
        cout << "\n";
    }
}

int minmult(int n, const int d[]){
    int i,j,k, diagonal, temp;
    int M[n+1][n+1];
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            M[i][j] = 0;
        }
    }
    for(diagonal = 0; diagonal<n; diagonal++ ){
        for(i=1; i<=n-diagonal; i++){
            j = i+diagonal;
            if(i==j){
                M[i][j] = 0;
                continue;
            }
            M[i][j] = Max;
            for(k = i; k <= j-1; k++){
                cout << k << endl;
                P[i][j] = (M[i][j] > M[i][k]+M[k+1][j]+(d[i-1]*d[k]*d[j])) ? k : P[i][j];
                M[i][j] = min(M[i][j], M[i][k]+M[k+1][j]+(d[i-1]*d[k]*d[j]));
            }
            cout << endl;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                cout << M[i][j] << " ";
            }
        cout << "\n";
        }
    }
    cout << "\n";
    return M[1][n];
}

void order(int i, int j){
    int k;
    if(i==j){
        cout << "A";
    }
    else{
        k = P[i][j];
        cout << "(";
        order(i,k);
        order(k+1, j);
        cout << ")";
    }
}

int main(){
    int d[7] = {5,2,3,4,6,7,8};
    int n=6;
    minmult(n,d);
    //order(4,6, P);

}