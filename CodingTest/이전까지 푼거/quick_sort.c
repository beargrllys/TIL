#include <stdio.h>
#define SWAP(X,Y,tmp) {tmp=X; X=Y; Y=tmp; }

int partition(int list[], int left, int right)
{
    int pivot=list[left], temp;
    int low = left, high = right+1;

    do{
        do{
            low++;
        }while(low <= right && list[low]<pivot);
        do{
            high--;
        }while(high >= left && list[high]> pivot);
        if(low < high){
            SWAP(list[low], list[high], temp);
        }
    }while(low<high);
    SWAP(list[left], list[high], temp);
    return high;
}

void quick_sort(int list[], int left, int right)
{
    if(left < right)
    {
        int q = partition(list,left,right);
        quick_sort(list, left, q);
        quick_sort(list, q+1, right);
    }
}

int main()
{
    int list[] = {5,2,7,9,4,1,3,0,8,10,}, i;
    quick_sort(list, 0, sizeof(list)/sizeof(int));
    for(i=0; i<(sizeof(list)/sizeof(int)); i++)
    {
        printf("%d ", list[i]);
    }
}