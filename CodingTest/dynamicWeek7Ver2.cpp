#include <iostream>
#include <cmath>

using namespace std;

int m[4][4]={{6,7,12,5},{5,3,11,18},{7,17,3,3},{8,10,14,9}};
int cash[5][5];

int mat(int row, int col, int n){
    int i,j;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==0 && j==0){
                cash[i][j] = m[0][0];
            }
            else if(i==0){
                cash[i][j] = m[i][j] + cash[i][j-1];
            }
            else if(j==0){
                cash[i][j] = m[i][j] + cash[i-1][j];
            }
            else{
                cash[i][j] = m[i][j] + min(cash[i-1][j], cash[i][j-1]);
            }
        }
    }
    return cash[n-1][n-1];
}

int main(){
    memset(cash, -1, sizeof(cash));

    mat(3,3, 4);
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
    for(i=0; i < 4; i++){
        for(j=0; j<4; j++){
            printf("%d  ", cash[i][j]);
        }
        printf("\n");
    }
    printf("(%d,%d)\n", 3,3);
    printf("최소합: %d", cash[3][3]);
}