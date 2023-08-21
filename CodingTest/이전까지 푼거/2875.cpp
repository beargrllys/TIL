#include <iostream>

using namespace std;

int main()
{
    int female, male, intern, team = 1;
    cin >> female >> male >> intern;
    while (1)
    {
        if ((team * 3) > (female + male - intern) || (team * 2) > female || team > male)
        {
            break;
        }
        team++;
    }
    cout << --team;
}