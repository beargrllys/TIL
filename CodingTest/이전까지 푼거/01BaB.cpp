#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct node
{
    int level;
    int profit;
    int weight;
    float bound;
} node_t;

const int ju_price[] = {40, 30, 50, 10}, ju_weight[] = {2, 5, 10, 5}, W = 16;
int maxprofit = 0;

float bound(node u)
{
    int j, k;
    int totweight;
    float result;
    if (u.weight >= W)
    {
        return 0;
    }
    else
    {
        result = u.profit;
        j = u.level + 1;
        totweight = u.weight;
        while (j <= sizeof(ju_price) / sizeof(ju_price[0]) && totweight + ju_weight[j] <= W)
        {
            totweight = totweight + ju_weight[j];
            result = result + ju_price[j];
            j++;
        }
        k = j;
        if (k <= sizeof(ju_price) / sizeof(ju_price[0]))
        {
            result = result + (W - totweight) * ju_price[k] / ju_weight[k];
        }
        return result;
    }
}

void knapsack3(int n)
{
    queue<node> Q;
    node u, v;
    while (!Q.empty())
    {
        Q.pop();
    }
    v.level = -1;
    v.profit = 0;
    v.weight = 0;
    v.bound = bound(v);
    maxprofit = 0;
    Q.push(v);
    while (!Q.empty())
    {
        v = Q.front();
        Q.pop();
        if (v.bound > maxprofit)
        {
            u.level = v.level + 1;
            u.weight = v.weight + ju_weight[u.level];
            u.profit = v.profit + ju_price[u.level];
            if (u.weight < W && u.profit > maxprofit)
            {
                maxprofit = u.profit;
            }
            u.bound = bound(u);
            if (u.bound > maxprofit)
            {
                Q.push(u);
            }
            u.weight = v.weight;
            u.profit = v.profit;
            u.bound = bound(u);
            if (u.bound > maxprofit)
            {
                Q.push(u);
            }
        }
    }
}

int main()
{
    knapsack3(0);
    cout << maxprofit << endl;
}