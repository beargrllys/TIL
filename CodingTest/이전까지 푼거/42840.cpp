#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers)
{
    int p1 = 0, p2 = 0, p3 = 0;
    int p2count = 0;
    int p2List[4] = {1, 3, 4, 5};
    int p3List[5] = {3, 1, 2, 4, 5};

    vector<int> answer;
    int maxval;
    for (int i = 0; i < answers.size(); i++)
    {
        if ((i % 5) + 1 == answers[i])
            p1++;
        //cout << answers[i] << " / " << p2List[p2count % 4] << endl;
        if ((i % 2) == 1)
        {
            if (answers[i] == p2List[p2count % 4])
            {
                p2++;
            }
            //cout << p2List[p2count % 4] << " ";
            p2count++;
        }
        else if ((i % 2) == 0)
        {
            if (answers[i] == 2)
            {
                p2++;
            }
            //cout << 2 << " ";
        }
        if (p3List[(i / 2) % 5] == answers[i])
        {
            p3++;
        }
        //cout << answers[i] << " : " << p1 << " / " << p2 << " / " << p3 << endl;
    }

    //cout << p1 << " / " << p2 << " / " << p3;
    maxval = max(p1, max(p2, p3));
    if (p1 == maxval)
        answer.push_back(1);
    if (p2 == maxval)
        answer.push_back(2);
    if (p3 == maxval)
        answer.push_back(3);

    return answer;
}
/*
555141
123451
212324
331122
*/
int main()
{
    vector<int> answers = {5, 5, 5, 1, 4, 1};
    vector<int> answ = solution(answers);
    for (int i = 0; i < answ.size(); i++)
    {
        cout << answ[i] << endl;
    }
    return 0;
}