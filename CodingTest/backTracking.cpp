#include<iostream>

using namespace std;


int W[8][8] = {{0,1,1,-1,-1,-1,1,1},{1,0,1,-1,-1,-1,1,1},{1,1,0,1,-1,1,-1,-1},{-1,-1,1,0,1,-1,-1,-1},{-1,-1,-1,1,0,1,-1,-1},{-1,-1,1,-1,1,0,1,-1},{1,1,-1,-1,-1,1,0,1},{1,1,-1,-1,-1,-1,1,0}};

const int n = 8;


int promising(int i, int next, int save[]){
    int j = 0;
    if(W[i][next] == -1 || W[i][next] == 0){
        return -1;
    }
    while(j < n){
        if(save[j] == next){
            return -1;
        }
        j++;
    }
    return next;
}

bool getAnswer(int save[]){
    for(int i=0; i<n; i++){
        if(save[i] == -1){
            return false;
        }
    }
    if(W[save[0]][save[n-1]] != 1){
        return false;
    }
    else{
        return true;
    }
}

void getRoad(int now_po, int count, int save[]){
        int next_node; 
        save[count] = now_po;
        if(getAnswer(save)){
            for(int h=0; h<n; h++){
                cout << save[h]+1 << " -> ";
            }
            cout << save[0]+1 << endl;
            exit(1);
        }
        else{
            for(int k=0; k<n; k++){
                save[count] = now_po;
                next_node = promising(now_po, k, save);
                if(next_node != -1){
                    getRoad(next_node,count+1,save);
                }
                else{
                    save[count] = -1;
                }
            }
        }
}

int main(){
    int startPoint;
    cin >> startPoint;
    int tracking[8] = {-1,-1,-1,-1,-1,-1,-1,-1};
    getRoad(startPoint-1, 0, tracking);
}