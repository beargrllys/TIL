#include <iostream>

using namespace std;


int sum(int n, int S[]){
    int i;
    int result;

    result = 0;
    for(i = 0; i<n; i++)
        result = result + S[i];
    return result;
}
int main(){
    int S[] = {1,5,3,6,4,8,9,10,2,7};

    int n = 10;
    cout << sum(n, S) << endl;
}