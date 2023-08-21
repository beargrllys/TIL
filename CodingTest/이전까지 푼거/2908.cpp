#include <iostream>

using namespace std;

int change_num(int num){
    int n1,n2,n3, result;
    n1 = num/100;
    num = num%100;
    n2 = num/10;
    num = num%10;
    n3 = num;
    result = (n3*100)+(n2*10)+(n1);
    return result;
}

int main(){
    int input1,input2;
    int change, result1, result2;
    cin >> input1;
    cin >> input2;
    result1 = change_num(input1);
    result2 = change_num(input2);
    if(result1 < result2){
        cout << result2;
    }
    else{
        cout << result1;
    }

}