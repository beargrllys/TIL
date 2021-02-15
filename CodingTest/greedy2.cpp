#include<iostream>
#include<string>

using namespace std;

int main()
{
    string number;
    int result=1;
    cin >> number;
    int* numList = new int[number.length()];
    for(int i=0; i<number.length() ; i++)
    {
        *(numList+i) = number[i]-'0';
    }
    for(int i=0; i<number.length(); i++)
    {
        if(result == 0)
        {
            result = result + (*(numList+i));
        }
        if(*(numList+i) == 1)
        {
            result++;
        }
        else if(*(numList+i) != 0)
        {
            result= result * (*(numList+i));
        }
    }
    cout << result << endl;
}