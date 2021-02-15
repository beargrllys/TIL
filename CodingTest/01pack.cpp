#include <iostream>
#define MAX(a,b) a<b? b:a

using namespace std;



void print(int w[]){
    for(int j=0; j<4; j++){
        cout << w[j] << " ";
    }
    cout << endl;
}

int get_weight(int i, int W, int w[], int p[]){
    //print(w);
    if(i<=0 || W<=0){//모든 무게를 채우거나 오버도리경우리거나 개수를 벗어날경우
        return 0;
    }
    if(w[i] > W){//무게가 초과하면 이전 값을 그대로 유지
        return get_weight(i-1,W,w,p);
    }
    else{//
        int left = get_weight(i-1,W,w,p);//보석을 집지 않고 이전 노드를 유지할경우
        int right = get_weight(i-1,W-w[i],w,p);// 새로운 보석을 집어들경우 
        cout << left <<" / " << right <<endl;
        return MAX(left,right+p[i]);// 두가지 경우 가치 비교
    }
}

int main(){
    int w[4] = {2,4,3,5}, P[4] = {3,5,4,6};
    int W=10;
    int temp = get_weight(3,W,w,P);
    cout << "Highest Value is "<< temp << endl;
}