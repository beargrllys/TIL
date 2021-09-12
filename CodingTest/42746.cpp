#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int out_val(vector<int> one, vector<int> ten, vector<int> hund)
{
    vector<int> list, idx;
    int set, index;
    if (one.size() != 0)
    {
        list.push_back(one.back() * 100);
        idx.push_back(100);
    }
    if (ten.size() != 0)
    {
        list.push_back(ten.back() * 10);
        idx.push_back(10);
    }
    if (hund.size() != 0)
    {
        list.push_back(hund.back());
        idx.push_back(1);
    }
    set = *max_element(list.begin(), list.end());
    index = max_element(list.begin(), list.end()) - list.begin();
    set = set / idx[index];
    cout << "Check : " << set << endl;
    return set;
}

string solution(vector<int> numbers)
{
    vector<int> one, ten, hund;
    string num;
    for (int i = 0; i < numbers.size(); i++)
    {
        if ((10 - numbers[i]) > 0)
            one.push_back(numbers[i]);
        else if ((100 - numbers[i]) > 0)
            ten.push_back(numbers[i]);
        else if ((1000 - numbers[i]) > 0)
            hund.push_back(numbers[i]);
    }
    if (one.size() != 0)
        sort(one.begin(), one.end());
    if (ten.size() != 0)
        sort(ten.begin(), ten.end());
    if (hund.size() != 0)
        sort(hund.begin(), hund.end());

    for (int i = 0; i < numbers.size(); i++)
    {
        int tmp = out_val(one, ten, hund);
        if (tmp == one.back())
        {
            num += to_string(one.back());
            one.pop_back();
        }
        else if (tmp == ten.back())
        {
            num += to_string(ten.back());
            ten.pop_back();
        }

        else if (tmp == hund.back())
        {
            num += to_string(hund.back());
            hund.pop_back();
        }
    }
    return num;
}

int main()
{
    vector<int> numbers = {3, 30, 34, 5, 9};
    cout << solution(numbers) << endl;
}