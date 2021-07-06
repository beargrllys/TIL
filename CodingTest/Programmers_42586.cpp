#include <string>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

typedef struct _process
{
    int idx;
    int progress;
    bool done;
} process;

bool Comp(const process &lhs, const process &rhs)
{
    return lhs.idx < rhs.idx;
}

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    list<process> stk;
    vector<process *> proList;
    vector<int> answer;
    int nowDeploy = 0;
    int day = 0;
    int popCnt = 0;

    for (int i = 0; i < progresses.size(); i++)
    { //Setting List for scheduling
        process *newPro = new process;
        newPro->idx = i;
        newPro->progress = progresses[i];
        newPro->done = false;
        proList.push_back(newPro);
    }

    while (nowDeploy != progresses.size())
    {
        day++;
        for (int i = 0; i < progresses.size(); i++)
        {
            proList[i]->progress += speeds[i];
            if (proList[i]->progress >= 100 && !proList[i]->done)
            {
                proList[i]->done = true;
                stk.push_back(*proList[i]);
            }
        }
        stk.sort(Comp);
        while (!stk.empty() && stk.front().idx == nowDeploy)
        {
            stk.pop_front();
            popCnt++;
            nowDeploy++;
        }
        if (popCnt != 0)
        {
            answer.push_back(popCnt);
            popCnt = 0;
        }
    }
    return answer;
}

int main()
{
    vector<int> progresses = {95, 90, 99, 99, 80, 99};
    vector<int> speeds = {1, 1, 1, 1, 1, 1};

    vector<int> sol = solution(progresses, speeds);

    for (int i = 0; i < sol.size(); i++)
        cout << sol[i] << " ";
}