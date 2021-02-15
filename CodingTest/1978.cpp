#include <iostream>
using namespace std;

int sosu(int num){
    if(num == 1){return 0;}
    if(num == 2){return 1;}
    if(num%2 == 0){return 0;}
    for(int i=3; i<num; i+=2){
        if(num%i == 0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int count=0,size, numlist[110];
    cin >> size;
    for(int i=0; i<size; i++){
        cin >> numlist[i];
    }
    for(int i=0; i<size; i++){
        if(sosu(numlist[i])){
            count++;
        }
    }
    cout << count <<endl;
}