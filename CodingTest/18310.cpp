#include <iostream>

using namespace std;

/*void quickSort(int arr[], int size) { 
    int pivot = arr[0]; 
    int cursor = 0; 
    for (int i = 1; i < size ; i++) { 
        if (pivot > arr[i]) { 
            cursor++; swap(arr[cursor], arr[i]); } 
            } 
            swap(arr[0], arr[cursor]); 
            if (cursor > 0) { 
                quickSort(arr, cursor); 
            } 
            if (cursor + 1 < size - 1) { 
                quickSort(arr + cursor + 1, size - cursor - 1); 
            } 
    }*/

int main()
{
    int N, minval=1000000000, temp=0, index=0;;
    cin >> N;
    int arr[N];
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    
    //quickSort(arr, N);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            temp += abs(arr[i]-arr[j]);
        }
        if(minval > temp){
            minval = temp;
            index = arr[i];
        }
        temp = 0;
    }
    cout << index <<endl;
}