#include <iostream>
#include <vector>
#include <string>

using namespace std;

void sort(int arr[][], int size)
{
    int tmp;
    int i_x, i_y;
    int j_x, j_y;
    int least_x, least_y;

    for (int i = 0; i < size * size; i++)
    {
        i_x = i / size;
        i_y = i % size;

        least_x = i_x;
        least_y = i_y;

        for (int j = i; j < size * size; j++)
        {
            j_x = j / size;
            j_y = j % size;

            if (arr[least_x][least_y] > arr[j_x][j_y])
            {
                least_x = j_x;
                least_y = j_y;
            }
        }
        tmp = arr[i_x][i_y];
        arr[i_x][i_y] = arr[least_x][least_y];
        arr[least_x][least_y] = tmp;
    }
}

int main()
{
    int limit = 50, result = 0, w = 0;
    int juwelry[3][3] = {{1, 10, 60}, {2, 20, 100}, {3, 30, 120}};
    int juwelry_sorted[3][3];
    sort(juwelry, 3);

    for (i = 0; i < len(juwelry); i++)
    {
        getIt = sorted_juwe[i] if (limit > w + sorted_juwe[i][3])
        {
            w += sorted_juwe[i][3] result = sorted_juwe[i][2]
        }
        else
        {
            if (w < limit)
            {
                result = (w / limit) * sorted_juwe[i][3]
            }
        }
    }