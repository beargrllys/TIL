#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    int i;
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    for (i = 0; participant[i] == completion[i]; i++)
    {
        ;
    }
    return participant[i];
}

int main()
{
    vector<string> participant = {"marina", "josipa", "nikola", "vinko", "filipa"};
    vector<string> completion = {"josipa", "filipa", "marina", "nikola"};
    solution(participant, completion);
    return 0;
}