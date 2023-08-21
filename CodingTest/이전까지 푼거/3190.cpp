#include <iostream>

using namespace std;

int N, apple_cnt ,apple_pos[110][2];
int turn_cnt, turn_time[10010];
char turn_direct[10010];

int gtime=0, direct=4, tail_x=0, tail_y=0, head_x=0, head_y=0, turning=0, appleing=0;

void move_toward(){
    gtime++;
    if(direct == 1){
        head_y--;
    }
    else if(direct == 2){
        head_x--;
    }
    else if(direct == 3){
        head_y++;
    }
    else if(direct == 4){
        head_x++;
    }
}

int main(){
    cin >> N;
    cin >> apple_cnt;
    for(int i=0; i<N; i++){
        cin >> apple_pos[i][0];
        cin >> apple_pos[i][1];
    }
    cin >> turn_cnt;
    for(int i=0; i<N; i++){
        cin >> turn_time[i];
        cin >> turn_direct[i];
    }
}



