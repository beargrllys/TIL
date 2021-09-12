#include <iostream>

using namespace std;

int Answer;
int cnt = 0, i = 0;

int find(int x, int Di[])
{
    if (Di[x - 1] == x)
    {
        return x;
    }
    else if (Di[x - 1] > cnt)
    {
        return Di[x - 1];
    }
    else
    {
        return Di[x - 1] = find(Di[x - 1], Di);
    }
}

void link(int x, int y, int Di[])
{
    Di[y] = find(x, Di);
}

int main(int argc, char **argv)
{
    int T, test_case;
    int over = 0, tmp;
    int Di[100100];
    cin >> T;
    for (test_case = 0; test_case < T; test_case++)
    {
        cin >> cnt;
        for (int k = 0; k < cnt; k++)
        {
            cin >> Di[k];
            if (Di[k] + k + 1 > cnt)
            {
                over += 1;
                Di[k] = cnt + over;
            }
            else
            {
                Di[k] = Di[k] + k + 1;
            }
        }
        while (i < cnt)
        {
            if (Di[i] < cnt)
            {
                if ((tmp = find(i, Di)) > cnt) // i 뒤에 따라오는게 있다.
                {
                    link(i, tmp, Di);
                }
            }
            i++;
        }
        i = 0;
        tmp = 0;
        for (int k = 0; k < cnt - 1; k++)
        {
            if (tmp < Di[k + 1])
                tmp = Di[k + 1];
        }
        Answer = tmp - cnt;

        // Print the answer to standard output(screen).
        cout << "Case #" << test_case + 1 << endl;
        cout << Answer << endl;
        over = 0;
    }

    return 0; //Your program should return 0 on normal termination.
}