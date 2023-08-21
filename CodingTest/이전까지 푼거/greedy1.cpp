#include<iostream>

using namespace std; 

int main()
{
    int N, K, count=0;
    cin >> N >> K;
    for(; N!=1; count++)
    {
        if(N % K != 0)
        {
            N--;
        }
        else if(N != 1)
        {
            N = N/K;
        }
    }
    cout << count << endl;
}