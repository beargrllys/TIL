#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> scoville, int K)
{
    priority_queue<int, vector<int>, greater<int>> queueSet;
    int pop_val = 0, snd_val = 0, count;
    for (int i = 0; i < scoville.size(); i++)
    {
        queueSet.push(scoville[i]);
    }
    for (count = 0; queueSet.top() < K; count++)
    {
        pop_val = queueSet.top();
        queueSet.pop();
        snd_val = queueSet.top();
        queueSet.pop();
        //cout << pop_val << snd_val << endl;
        pop_val = pop_val + (snd_val * 2);
        queueSet.push(pop_val);
        if (queueSet.size() == 1)
        {
            if (queueSet.top() < K)
                return -1;
        }
    }
    return count;
}

int main()
{
    cout << solution({10, 10, 10, 10, 10}, 100) << 4 << endl;
    cout << solution({1, 1, 1}, 4) << 2 << endl;
    cout << solution({1, 2, 3, 9, 10, 12}, 7) << 2 << endl;
    cout << solution({0, 2, 3, 9, 10, 12}, 7) << 2 << endl;
    cout << solution({0, 0, 3, 9, 10, 12}, 7) << 3 << endl;
    cout << solution({0, 0, 0, 0}, 7) << -1 << endl;
    cout << solution({0, 0, 3, 9, 10, 12}, 7000) << -1 << endl;
    cout << solution({0, 0, 3, 9, 10, 12}, 0) << 0 << endl;
    cout << solution({0, 0, 3, 9, 10, 12}, 1) << 2 << endl;
    cout << solution({0, 0}, 0) << 0 << endl;
    cout << solution({0, 0}, 1) << -1 << endl;
    cout << solution({1, 0}, 1) << 1 << endl;
    cout << solution({1, 1, 2}, 3) << 2 << endl;
}