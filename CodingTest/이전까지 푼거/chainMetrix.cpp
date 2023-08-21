#include <iostream>
#include <cmath>
#define MAX 500

using namespace std;

int M[MAX][MAX];

int print_arr(int size, int P[MAX][MAX]){
    int i,j;
    char temp;
    for(i=0; i<size; i++){
        for(j=0; j<size; j++){
            cout << P[i][j] << "  ";
        }
        cout << "\n";
    }
    cout << "\n" << endl;
}

int minmult(int arrSize, const int d[], int P[MAX][MAX]){
    int i,j,k,diag,minVal=INT_MAX;
    for(i=0; i<arrSize; i++){
        M[i][i] = 0;
    }
    for(diag = 1; diag <= arrSize; diag++){
        for(i=0; i < arrSize-diag; i++){
            j = i + diag;
            for(k = i; k <= j-1; k++){
                minVal = M[i][k]+M[k+1][j]+(d[i]*d[k+1]*d[j+1]);
                if(M[i][j] > minVal || M[i][j] == -1){
                    M[i][j] = minVal;
                    P[i][j] = k;
                }
            }
        }
    }
    print_arr(arrSize, P);
    return M[0][arrSize-1];
}

void order(int i, int j, int P[MAX][MAX]){
    int k;
    if(i==j){
        cout << "A" << i;
    }
    else{
        k = P[i][j];
        cout << "(";
        order(i,k, P);
        order(k+1,j, P);
        cout << ")";
    }
}

int main(){
    int d[MAX], P_arr[MAX][MAX];
    int i, arrSize = 0;
    int minimum;
    int (*P)[MAX] = P_arr;

    for(int i=0; i<MAX; i++){
        memset(M[i], -1, sizeof(int)* MAX);
    }

    cout << "크기를 입력해주세요: ";
    cin >> arrSize;
    cout << "행렬의 크기를 입력해주세요: ";
    for(i=0; i<arrSize+1; i++){
        cin >> d[i];
    }
    cout << endl;

    minimum = minmult(arrSize, d, P);
    order(0, arrSize-1, P);
    cout  << minimum;
}