#include <iostream>
using namespace std;

int row=0, count=0, val, r=0, c=0, i,j,f,e;
//int S[6][6] = {{0, 1, 0, 0, 0, 0}, {0, -1, 1, 0, -1, 0}, {0, 0, 0, -1, 0, 0}, {0, 1, 0, 0, 1, 0}, {0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 0}};
int S[6][6] = {
   {0,1,0,1,0},
   {0,-1,0,-1,-1},
   {0,1,0,0,0},
   {0,0,-1,-1,1},
   {0,0,0,1,0}};
int dt[6][6],d[6],J[6][6];

void print(int dt[][6]){
    for(int i=0; i < 5; i++){
        for(int j=0; j < 5; j++){
            cout << dt[i][j] << " ";
        }
        cout << "    ";
        for(int j=0; j < 5; j++){
            cout << J[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int save;
    for(f = 4; f >= 0; f--){
        for(e = 4; e>=0; e--){//열
            if(e==4 && f == 4){
                dt[e][f] = S[e][f];
            }
            else if(f == 4){
                dt[e][f] = dt[e+1][f] + S[e][f];
            }
            else{
                dt[e][f] = -10;
                for(i=0; i<=4; i++){
                    save = d[i];
                    d[i] = dt[i][f+1];
                    if(i>e){
                        for(j=i; j >= e; j--){
                        d[i] += S[j][f];
                        }
                    }
                    else if(i==e){
                        d[i] += S[i][f];
                    }
                    else{
                        for(j=i; j <= e; j++){
                            d[i] += S[j][f];
                        }
                    }
                    if(dt[e][f] < d[i]){
                        dt[e][f] = d[i];
                        J[e][f] = i;
                        save = i;
                    }else{
                    }
                }
            }
        }
        row = 0; r=c=4;
        d[4] = 0;
        for(i=4; i<=0; i--){
            d[i+1] = J[d[i]][i];
        }
    }
    print(dt);
    for(i=0; i<=4; i++){
            printf("%d -> ",d[i+1]);
    }
}