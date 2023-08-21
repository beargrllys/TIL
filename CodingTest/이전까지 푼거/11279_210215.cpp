#include <iostream>
#include <vector>

using namespace std;

struct node
{
    int val;
    int left_idx;
    int right_idx;
};

int ipt_size;

void insertHeap(vector<node> *Tree, int new_val)
{
}

void showHeap(vector<node> Tree)
{
    int level = 0, last = Tree.size();
    while (last < 2 ^ level)
    {
        last = last - 2 ^ level;
        level++;
    }
    for (int i = 0; i < level; i++)
    {
        for (int j = 0; j < 2 ^ level; j++)
        {
            cout << Tree[i].val << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<node> heapList;
    int ipt_now;
    cin >> ipt_size;
    for (int i = 0; i < ipt_size; i++)
    {
        cin >> ipt_now;
        if (ipt_now == 0)
        {
        }
        else
        {
        }
    }
}