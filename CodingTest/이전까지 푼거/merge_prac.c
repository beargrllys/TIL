#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void partition(int list[], int left, int mid, int right)
{
    int i,j,k,l;
    int* temp = malloc(sizeof(int)* (right-left));
    i = left;
    j = mid+1;
    k = 0;

    while(i <= mid && j <= right)
    {

        if(list[i] < list[j])
        {
            *(temp+k) = list[i++];
            k++;
        }
        else
        {
            *(temp+k) = list[j++];
            k++;
        }
    }

    while(i <= mid)
    {
        *(temp+k) = list[i++];
        k++;
    }
    while(j <= right)
    {
        *(temp+k) = list[j++];
        k++;
    }
    for(l=0; l <= (right-left); l++)
    {
        list[left+l] = *(temp+l);
    }
    
}

void merge_sort(int list[], int left, int right)
{
    int mid;
    if(left < right)
    {
        mid = (right+left)/2;
        merge_sort(list, left, mid);
        merge_sort(list, mid+1, right);
        partition(list, left, mid, right);
    }
}

int main()
{
    int i, N, result=0;
    int *list;
    char* input;
    scanf("&d\n", &N);
    list = malloc(sizeof(int)* N);
    scanf("&s\n", input);
    *list = strtok(input, ",");
    for(i=1; i<N; i++)
    {
        *(list+i) = strtok(NULL, ",");
    }
    merge_sort(list, 0, N-1);

    for(i=0; i<N; i++)
    {
        if(list[i]%2 == 0)
        {
            result+=list[i];
        }
        else
        {
            result-=list[i];
        }
    }
    printf("%d", result);
}