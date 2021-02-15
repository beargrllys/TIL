/*
1.MAIN ()
{
    선언) 정수 N, list[], result
    입력1) N : 리스트의 크기
    입력2) list : 리스트자체 입력

    함수 호출) quick_sort(list, 0, N-1) //리스트 정렬
    
    결과값 가공)
    반복문 시작 (i를 0 부터 N까지)//리스트 크기만큼 반복
        만약 i%2==0 이면 //짝수번째 값
            result를 list[i] 만큼 빼기
        그게 아니면 // 홀수번째 값
            result를 list[i] 만큼 더하기
    반복문 종료

    출력) result
}
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SWAP(X,Y,temp) {temp=Y; Y=X; X=temp;}

int partition(int list[], int left, int right)
{
    int mid = left+right/2;
    int pivot=list[left], temp;
    int low = left, high = right+1;

    do{
        do{
            low++;
        }while(low <= right && list[low]<pivot);
        do{
            high--;
        }while(high >= left && list[high]>pivot);
        if(low < high){
            SWAP(list[low], list[high], temp);
        }
    }while(low<high);
    SWAP(list[left], list[high], temp);
    return high;
}

void quick_sort(int list[], int left, int right)
{
    if(left<right)
    {
        int q = partition(list, left, right);
        quick_sort(list, left, q);
        quick_sort(list, q+1, right);
    }
}

int main()
{
    int i, N, result=0;
    int *list = NULL;
    char input[500], *temp;

    scanf("%d", &N);
    list = malloc(sizeof(int)* N);
    scanf(" %s", input);


    *list = atoi(strtok(input, ","));
    for(i=1; i<N; i++)
    {
        *(list+i) = atoi(strtok(NULL, ","));
    }


    quick_sort(list, 0, N-1);


    for(i=0; i<N; i++)
    {
        if(i%2 == 0)
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