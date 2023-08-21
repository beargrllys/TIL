#include <iostream>
#define MAX 50
using namespace std;

int arr[MAX];
int N, total = 0;

bool catchCheck(int level)// 잡히는 지 체크 하는 함수
{
    for(int i = 0; i < level; i++)
        if(arr[i] == arr[level] || abs(arr[level] - arr[i]) == level - i)//같은 대각선방향에 있거나 같은 열, 행에 있는경우
            return false; //잡힐수 있다고 반환
    return true;//이상 없다고 반환
}

void queen(int x)
{
    if(x == N)// 판의 크기를 모두 잡히지 않는 포지션에서 배정되는 지 체크
        total++;// 모든 말에 대한 체크가 끝나고 방법수 증가
    else
    {
        for(int i = 0; i < N; i++)// 같은 열에 대한 행값을 반복해야함
        {
            arr[x] = i;//해당 행이 몇번째 열까지 돌아가는 지 배열에 저장
            if(catchCheck(x)){// 잡하는지 체크
                queen(x+1);// 다음 행으로 재귀적으로 넘어감
            }
        }
    }
}
int main() {
    cin >> N;
    queen(0);
    cout << total;
}