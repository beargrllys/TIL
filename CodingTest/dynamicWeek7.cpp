#include <iostream>
#include <cmath>

using namespace std;

int m[4][4]={{6,7,12,5},{5,3,11,18},{7,17,3,3},{8,10,14,9}};
int cash[5][5];

int mat(int i, int j){
    if(cash[i][j] != -1){
        return cash[i][j];
    }
    if(i==0 && j==0){
        cash[i][j] = m[i][j];
    }
    else if(i==0){
        cash[i][j] = mat(i,j-1) + m[i][j];
    }
    else if(j==0){
        cash[i][j] = mat(i-1,j) + m[i][j];
    }
    else{
        cash[i][j] = m[i][j] + min(cash[i-1][j], cash[i][j-1]);
    }
    return cash[i][j];
}


int main(){
    memset(cash, -1, sizeof(cash));

    mat(3,3);
    int i=0,j=0;
    printf("세로,가로\n(%d,%d)\n", i,j);
    while(j!=3 && i!=3){
        if(cash[i+1][j] <= cash[i][j+1]){
            printf("(%d,%d)\n", ++i,j);
        }
        else{
            printf("(%d,%d)\n", i,++j);
        }
    }
    printf("(%d,%d)\n", 3,3);
    printf("최소합: %d", cash[3][3]);
}