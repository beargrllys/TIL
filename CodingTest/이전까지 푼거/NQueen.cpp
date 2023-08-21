#include <iostream>
#define SIZE 10;

using namespace std;


void init(int M[]){
    for(int i=0; i<10; i++){
        M[i] = 0;
    }
}

void printM(int M[]){
    for(int i=0; i< 10; i++){
        cout << M[i] << " ";   
    }
    cout <<endl;
}

void print(int M[]){
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if(j == M[i]){
                cout << "X";
            }
            else{
                cout << "O";
            }
        }
        cout << endl;
    }
    cout << endl;
}

bool promising(int M[], int col){
    bool prom = true;
    int i=0;
    while(i<col && prom){
        if(M[i] == M[col] || abs(M[col] - M[i]) == col-i){
            prom = false;
        }
        
        i++;
    }
    return prom;
}

void Nqueen(int M[], int col){
    if(promising(M, col)){
        if(col == 10){
            print(M);
            exit(1);
        }
        else{
            for(int j=1; j<=10; j++){
                M[col+1] = j;
                Nqueen(M,col+1);
            }
        }
    }
}

int main(){
    int M[10];
    init(M);
    Nqueen(M,0);
}