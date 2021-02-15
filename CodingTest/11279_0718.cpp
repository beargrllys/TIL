#include <iostream>
#include <deque>
using namespace std;

int main()
{
    int input_count, value, max = 0, size;
    deque<int> priority_queue, result;
    cin >> input_count;
    for (int i = 0; i < input_count; i++)
    {
        cin >> value;
        max = 0;
        size = priority_queue.size();
        if (value == 0)
        {
            if (size != 0)
            {
                int j = 0, index = 0;
                for (j = 0; j < size; j++)
                {
                    index = priority_queue[j] > max ? j : index;
                    max = priority_queue[j] > max ? priority_queue[j] : max;
                }
                result.push_back(max);
                priority_queue.erase(priority_queue.begin() + index);
            }
            else
            {
                result.push_back(0);
            }
        }
        else
        {
            priority_queue.push_back(value);
        }
    }
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }
}
