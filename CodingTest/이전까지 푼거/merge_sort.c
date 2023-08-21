//합병정렬 :부분문제가 1/2로 나뉘는 문제 해결법
#include <stdio.h>
#define SWAP(X,Y,tmp) {tmp=X; X=Y; Y=tmp; }

int sorted[10];

void merge(int list[], int left, int mid, int right)
{
    int i,j,k,l;
    i = left;
    j = mid+1;
    k = left;

    while(i<=mid && j<=right)
    {
        if(list[i] <= list[j])
        {
            sorted[k++] = list[i++];
        }
        else
        {
            sorted[k++] = list[j++];
        }
    }
    if(i>mid)
    {
        for(l=j; l<=right; l++)
        {
            sorted[k++] = list[l];
        }
    }
    else
    {
        for(l=i; l<=mid; l++)
        {
            sorted[k++] = list[l];
        }
    }
    for(l = left; l<=right; l++)
    {
        list[l] = sorted[l];
    }
}

void merge_sort(int list[], int left, int right)
{
    int mid;
    if(left < right)
    {
        mid = (left+right)/2;
        merge_sort(list, left, mid);
        merge_sort(list, mid+1, right);
        merge(list, left, mid, right);
    }

}

int main()
{
    int i;
    int list[] = {5,2,7,9,4,1,3,0,8,6};
    merge_sort(list, 0, (sizeof(list)/sizeof(int))-1);
    for(i=0; i<(sizeof(list)/sizeof(int)); i++)
    {
        printf("%d ", list[i]);
    }
}