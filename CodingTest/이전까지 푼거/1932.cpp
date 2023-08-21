#include <iostream>

using namespace std;

int main()
{
    int size, arr[510][510], i, j, ans[510][510], answer = 0;
    cin >> size;
    for (i = 1; i <= size; i++)
    {
        for (j = 0; j < i; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (i = 1; i <= size; i++)
    {
        for (j = 0; j <= i; j++)
        {
            if (j == 0)
            {
                ans[i][j] = ans[i - 1][j] + arr[i][j];
            }
            else if (i == j)
            {
                ans[i][j] = ans[i - 1][j - 1] + arr[i][j];
            }
            else
            {
                ans[i][j] = max(ans[i - 1][j] + arr[i][j], ans[i - 1][j - 1] + arr[i][j]);
            }
            if (i == size)
            {
                answer = max(answer, ans[i][j]);
            }
        }
    }
    cout << answer << endl;
}