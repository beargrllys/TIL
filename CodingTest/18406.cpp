#include <iostream>

using namespace std;

int main(){
    string str;
    cin >> str;
    int i=0, left=0, right=0;
    for(int j=i; j< str.length()/2; j++){
        left += (int)str[j];
        i++;
    }
    for(int j=i; j< str.length(); j++){
        right += (int)str[j];
        i++;
    }
    if(left == right){
        cout << "LUCKY" << endl;
    }
    else{
        cout << "READY" << endl;
    }
}