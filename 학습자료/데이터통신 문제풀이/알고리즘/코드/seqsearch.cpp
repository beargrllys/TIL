#include <iostream>

using namespace std;


void seqsearch(int n, int S[], int x, int* location){

    while(*location <= n && S[*location] != x){
        //cout << *location << endl;
        *location += 1;
    }

    if(*location > n)
        *location = 0;
}
int main(){
    int S[] = {1,5,3,6,4,8,3,10,2};

    int n = 9;
    int location = 0;
    seqsearch(n, S, 8, &location);
    cout << location << endl;
}