#include <iostream>
#define INF 900;

using namespace std;

int nearest[5] = {-1,-1,-1,-1,-1};
int dist[5] = {100,100,100,100,100};

void print(){
    cout << "Nearest" << endl;
    cout << "1 ";
    for(int i=0; i< 4; i++){
        cout << nearest[i]+1 << " ";
    }
    cout << "\n" << "Distance" <<endl;
    for(int i=0; i< 4; i++){
        cout << dist[i] << " ";
    }
}

void prim(int W[][5], int node){
    int min = 100, index = 0;
    for(int i = 0; i <4; i++){
        for(int j = 0; j < 5; j++){
            if(W[i][j] != -1 && W[i][j] != 0){
                index = (W[i][j] < min) ? j : index;
                min = (W[i][j] < min) ? W[i][j] : min;
            }
        }
        cout << i+1 << "에서 가장 가까운 곳은 " << index+1 <<" / 거리는 " << min << "입니다." << endl;
        W[i][index] = -1;
        W[index][i] = -1;
        nearest[i] = index;
        dist[i] = min;
        min = 100;
        index = 0;
        for(int j = 0; j < 5; j++){
            W[i][j] = -1;
        }
    } 
}

int main(){
    int grap[5][5] = {{0,1,3,-1,-1},{1,0,3,6,-1},{3,3,0,4,2},{-1,6,4,0,5},{-1,-1,2,5,0}};
    int input;
    //cin >> input;
    prim(grap, 0);
    print();
}