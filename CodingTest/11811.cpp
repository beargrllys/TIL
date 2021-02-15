#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
    int size, save_num = 0;
    vector<vector<int>> letter(1010, vector<int>(1010, 0));
    vector<int> result(1010, 0);
    string columns;
    getline(cin, columns);
    size = atoi(columns.c_str());
    // for (int i = 0; i < size + 10; i++)
    // {
    //     vector<int> *temp = new vector<int>;
    //     letter[i] = *temp;
    // }

    for (int i = 0; i < size; i++)
    {
        string column;
        getline(cin, column);
        int k = 0;
        for (int j = 0; j < size + 10; j++)
        {
            while (column[k] != ' ' && k < (int)column.length())
            {
                save_num = (save_num * 10) + (column[k] - '0');
                k++;
            }
            k++;
            letter[i][j] = save_num;
            save_num = 0;
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i != j)
            {
                result[i] = result[i] | letter[i][j];
                result[j] = result[j] | letter[i][j];
            }
        }
    }
    for (int i = 0; i < size; i++)
    {
        cout << result[i] << ' ';
    }

    return 0;
}