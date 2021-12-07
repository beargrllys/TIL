#include <iostream>

using namespace std;


void binarySearch(int n, int S[], int x, int* location){

    int low, high, mid;
    low = 1; high = n;
    *location  = 0;

    while(low <= high && *location == 0){
        mid = (low+high)/2;
        if(x == S[mid])
            *location = mid;
        else if(x < S[mid])
            high = mid - 1;
        else 
            low = mid + 1;
    }
}
int main(){
    int S[] = {1,5,3,6,4,8,3,10,2};

    int n = 9;
    int location = 0;
    binarySearch(n, S, 8, &location);
    cout << location << " ";
}