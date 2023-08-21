#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;
using std::string;

void print_func(int num);
void quickSort(int iptArr[], int left, int right, int Casetype);
int partition(int array[], int low, int high, int Casetype);
void swap(int array[], int i, int j);
int mid(int a, int b, int c);
int randNum(int low, int high);
int mid(int array[], int a, int b, int c);

int input_size = 1000000;

int compare = 0;
int exchanges = 0;

int main()
{
    fstream dataFile;
    string str("");
    int *ipt_array;

    //cin >> input_size;
    ipt_array = new int[input_size];

    for (int i = 0; i < input_size; i++)
        ipt_array[i] = randNum(0, 99999999);

    //cout << "Original : ";
    //for_each(ipt_array, &ipt_array[input_size], print_func);
    cout << "\n\n";

    int *iptCpy1 = new int[input_size];
    compare = 0, exchanges = 0;
    copy(ipt_array, ipt_array + input_size, iptCpy1);
    quickSort(iptCpy1, 0, input_size - 1, 1);

    cout << "First Element Sorted : ";
    //for_each(iptCpy1, &iptCpy1[input_size], print_func);
    //cout << "\n";
    cout << "Compare : " << compare << " / Exchange : " << exchanges << "\n\n";
    str.append(to_string(compare)).append("\t").append(to_string(exchanges)).append("\t");

    int *iptCpy2 = new int[input_size];
    compare = 0, exchanges = 0;
    copy(ipt_array, ipt_array + input_size, iptCpy2);
    quickSort(iptCpy2, 0, input_size - 1, 2);

    cout << "Random Element Sorted : ";
    //for_each(iptCpy2, &iptCpy2[input_size], print_func);
    //cout << "\n";
    cout << "Compare : " << compare << " / Exchange : " << exchanges << "\n\n";
    str.append(to_string(compare)).append("\t").append(to_string(exchanges)).append("\t");

    int *iptCpy3 = new int[input_size];
    compare = 0, exchanges = 0;
    copy(ipt_array, ipt_array + input_size, iptCpy3);
    quickSort(iptCpy3, 0, input_size - 1, 3);

    cout << "Median Element Sorted : ";
    //for_each(iptCpy3, &iptCpy3[input_size], print_func);
    //cout << "\n";
    cout << "Compare : " << compare << " / Exchange : " << exchanges << "\n\n";
    str.append(to_string(compare)).append("\t").append(to_string(exchanges)).append("\n");
    cout << str << endl;

    char *charArr = new char[str.length()];
    strcpy(charArr, str.c_str());
    dataFile.open("data.txt", ios::app);
    dataFile.write(charArr, str.length());
}

void print_func(int num)
{
    cout << num << " ";
}

int randNum(int low, int high)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(low, high);
    return dis(gen);
}

void quickSort(int iptArr[], int low, int high, int Casetype)
{
    compare++;
    if (low < high)
    {
        int pivot = partition(iptArr, low, high, Casetype);
        quickSort(iptArr, low, pivot - 1, Casetype);
        quickSort(iptArr, pivot + 1, high, Casetype);
    }
}

int partition(int array[], int low, int high, int Casetype)
{
    int i = low + 1;
    int j = high;
    int pivot_item;
    if (Casetype == 1)
    { //맨앞원소 선정
        pivot_item = low;
    }
    else if (Casetype == 2)
    { //랜덤 변수 선언
        int item = randNum(low, high);
        swap(array, item, low);
        pivot_item = low;
    }
    else if (Casetype == 3)
    { //중간값
        int mid_val = mid(array, low, ((low + high) / 2), high);
        swap(array, mid_val, low);
        pivot_item = low;
    }
    while (i <= j)
    {
        compare++;
        while (i <= high && array[i] <= array[pivot_item])
        {
            compare += 2;
            i++;
        }
        while (j > low && array[j] >= array[pivot_item])
        {
            compare += 2;
            j--;
        }
        compare++;
        if (i > j)
        {
            swap(array, pivot_item, j);
        }
        else
        {
            swap(array, i, j);
        }
    }

    return j;
}

void swap(int array[], int i, int j)
{
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
    exchanges++;
}

int mid(int array[], int a, int b, int c)
{
    compare++;
    if (array[a] < array[b])
    {
        compare++;
        if (array[b] < array[c])
        {
            return b;
        }
        else
        {
            compare++;
            if (array[c] < array[a])
                return a;
            else
                return c;
        }
    }
    else //a>b
    {
        compare++;
        if (array[a] < array[c])
        {
            return a;
        }
        else
        {
            compare++;
            if (array[c] < array[b])
                return b;
            else
                return c;
        }
    }
}