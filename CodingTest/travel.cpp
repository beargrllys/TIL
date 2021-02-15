#include <iostream>
#include <queue>
#define SIZE 4
#define INF 59999

using namespace std;

typedef struct node{
    int level;
    int bound;
    int path[SIZE] = {[0 ...SIZE-1]=-1};
}node;

int minLength, opttour[SIZE];
const int W[4][4] = {{0,2,9,INF},{1,0,6,4},{INF,7,0,8},{6,3,INF,0}};

int length(node u){
    int leng = 0, j;
    for(int i=0; i<3 && u.path[i] != -1; i++){
        leng += W[u.path[i]][u.path[i+1]];
    }
    return leng;
}
int last_val(int arr[]){
    int j;
    for(j=0; arr[j]!=-1; j++){}
    return arr[j-1];
}

bool search_val(int arr[], int i){
    for(int j=0; j<SIZE; j++){
        if(arr[j] == i){
            return true;
        }
    }
    return false;
}

bool outgoing_val(int arr[], int i){
    for(int j=0; j<i; j++){
        if(arr[j] == i){
            return false;
        }
    }
    return true;
}

bool incoming_val(int arr[], int i){
    for(int j=i; j<SIZE; j++){
        if(arr[j] == i){
            return false;
        }
    }
    return true;
}

int bound(node t){
    int min=0, total = length(t);
    for(int i = 0; i< SIZE; i++){
        if(outgoing_val(t.path,i)){
            continue;
        }
        min = INF;
        for(int j=0; j<SIZE; j++){
            if(i == j){continue;}
            if(incoming_val(t.path,j)){continue;}
            if(j == 1 && i == last_val(t.path)){continue;}
            if(min > W[i][j]){min = W[i][j];}
        }
        total += min;
    }
    return total;
}

void insert_val(int arr[], int i){
    int j;
    for(j=0; arr[j]!=-1; j++){}
    arr[j] = i;
    cout << "insert arr[" << j << "]: " << i << endl;
}

void insert_remain(int arr[]){
    for(int j=0; j<SIZE; j++){
        cout << "Check: " << j <<endl;
        if(!search_val(arr, j)){
            insert_val(arr,j);
        }
    }
}

void copy_arr(int paste[], int copy[]){
    for(int i=0; i<SIZE; i++){
        paste[i] = copy[i];
    }
}

void travel(){
    queue<node> PQ;
    node u,v;

    while(!PQ.empty()){
        PQ.pop();
    }
    v.level = 0;
    v.path[0] = 0;
    v.bound = bound(v);
    minLength = INF;
    PQ.push(v);
    while(!PQ.empty()){
        v = PQ.front();
        PQ.pop();
        if(v.bound < minLength){
            u.level = v.level + 1;
            for(int i=1; i<=SIZE; i++){
                if(search_val(u.path, i)){
                    continue;
                }
                copy_arr(u.path, v.path);
                insert_val(u.path, i);
                if(u.level == SIZE-2){
                    insert_remain(u.path);
                    insert_val(u.path, 1);
                    for(int i = 0; i< SIZE; i++){
                        cout << v.path[i] << " ";
                    }
                    cout << endl;
                    if(length(u) < minLength){
                        minLength = length(u);
                        copy_arr(opttour, u.path);
                    }
                }
                else{
                    u.bound = bound(u);
                    if(u.bound < minLength){
                        PQ.push(u);
                    }
                }
            }
        }
    }
}

int main(){
    travel();
    cout << minLength << endl;
}