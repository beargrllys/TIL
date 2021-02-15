#include <iostream>
#include <cmath>

using namespace std;

int mins(char* str, int size){
    int minNum=10,indexs=0;
    for(int i=0; i<size; i++){
        minNum = min(minNum, str[i]-'0');
        indexs = (minNum < str[i]-'0') ? indexs : i;
    }
    return indexs;
}

int main(){
    char num_str[500050];
    int many, del, idx, result=0,j=0;
    scanf("%d", &many);
    scanf("%d", &del);
    scanf("%s", num_str);
    for(int i=0; i<del; i++){
        idx = mins(num_str, many);
        num_str[idx] = 'd';
    }
    j = many-del-1;
    for(int i=0; i<many; i++){
        if(num_str[i]-'0' <= 9){
            result += (num_str[i]-'0')*pow(10,j);
            j--;
        }
    }
    printf("%d",result);
}