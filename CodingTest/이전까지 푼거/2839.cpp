#include <iostream>

using namespace std;

int main(){
    int weight ,count=0 ;
    cin >> weight;
    count += weight/5;
    weight = weight%5;
    if(count>0){
        if(weight == 0){
            cout << count << endl;
        }
        else if(weight == 1){
            cout << count+1 << endl;
        }
        else if(weight == 2){
            if(count >= 2){
                cout << count+2 << endl;
            }
            else{
                cout << "-1" << endl;
            }
        }
        else if(weight == 3){
            cout << count+1 << endl;
        }
        else if(weight == 4){
            cout << count+2 << endl;
        }
    }
    else{
        count += weight/3;
        weight = weight%3;
        if(weight == 0){
            cout << count << endl;
        }
        else{
            cout << "-1" << endl;
        }
    }
}