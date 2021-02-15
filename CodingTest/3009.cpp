#include <iostream>

using namespace std;

int main(){
    int x[3],y[3],r_x,r_y;
    for(int i=0; i<3; i++){
        cin >> x[i];
        cin >> y[i];
    }
    if(x[0]==x[1]){
        r_x = x[2];
    }
    else if(x[1]==x[2]){
        r_x = x[0];
    }
    else if(x[0]==x[2]){
        r_x = x[1];
    }
    if(y[0]==y[1]){
        r_y = y[2];
    }
    else if(y[1]==y[2]){
        r_y = y[0];
    }
    else if(y[0]==y[2]){
        r_y = y[1];
    }

    cout << r_x << " " << r_y << endl;
}