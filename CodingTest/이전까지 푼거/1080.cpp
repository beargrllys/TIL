#include <iostream>
#include <string>
using namespace std;

int main(){
    int N,M, A[55][55], B[55][55], check[55][55], offset=0, reverse=0, count=0;
    string temp;
    cin >> N;
    cin >> M;
    for(int i=0; i<N; i++){
        cin >> temp;
        for(int j=0; j<M; j++){
            A[i][j] = temp.at(j) - '0';
        }
    }
    for(int i=0; i<N; i++){
        cin >> temp;
        for(int j=0; j<M; j++){
            B[i][j] = temp.at(j) - '0';
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(A[i][j] != B[i][j]){
                check[i][j] = 1;
            }
            else{
                check[i][j] = 0;
            }
        }
    }
    for(int h=0+offset; h+2<3+offset; h++){
        for(int i=0+offset; i+2<3+offset; i++){
            for(int j=i; j<i+3; j++){
                for(int k=i; k<i+3; k++){
                    if(check[j][k] || reverse){
                        check[j][k] = (check[j][k] == 0) ? 1 : 0; 
                    }
                }
            }
            if(reverse){
                count++;
            }
        }
        if(check[h][N-1] || check[h][N-2] || check[h][N-3]){
            cout << -1;
        }
    }
    cout << count;
}