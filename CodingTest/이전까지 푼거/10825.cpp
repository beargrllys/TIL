#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

struct Score
{
    char name[11];
    int kor;
    int eng;
    int math;
};

bool compare(const Score &s1, const Score &s2)
{
    if (s1.kor != s2.kor)
    {
        return s1.kor > s2.kor;
    }
    else if (s1.eng != s2.eng)
    {
        return s1.eng < s2.eng;
    }
    else if (s1.math != s2.math)
    {
        return s1.math > s2.math;
    }
    else
    {
        if (strcmp(s1.name, s2.name) < 0)
        {
            return true;
        }
        return false;
    }
}

int main()
{
    int n;
    cin >> n;

    vector<Score> vec(n);

    for (int i = 0; i < n; i++)
    {
        cin >> vec[i].name >> vec[i].kor >> vec[i].eng >> vec[i].math;
    }

    sort(vec.begin(), vec.end(), compare);

    for (int i = 0; i < n; i++)
    {
        cout << vec[i].name << '\n';
    }
}