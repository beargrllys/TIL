#include <stdio.h>
#include <string.h>

void *copy(char *make, char *copyed, int start, int end)
{
    int i = 0;
    while (i < (end-start))
    {
        make[i] = copyed[start+i];
        i++;
    }
}

int solution(char *s, int count)
{
    int shortest_len, str_len, now_len = 0, temp1, temp2;
    ; //(shortest_len=가장 짧은 길이 저장)
    str_len = count - 1;
    for (int i = 1; i <= str_len; i++) //전체 압축길이 돌리는 반복문(i=쪼개는 문자 개수)
    {
        int repeat = 0, pice_count = 0;
        while (pice_count < (str_len / i)) //현재 쪼개진 조각과 전체 검사될 조각 개수 컨트롤
        {
            char B_pice[i];
            char N_pice[i];
            copy(B_pice, s,pice_count*i,(pice_count*(i+1)));
            copy(N_pice, s,pice_count*(i+1),(pice_count*(i+2)));
            if (strcmp(B_pice, N_pice) == 0)
            { //0:2   3:5
                repeat++;
                pice_count++;
            }
            else
            {
                now_len = now_len + i;
                now_len = now_len + (repeat / 10) + 1;
                repeat = 0;
            }
        }
        if (shortest_len > now_len)
        {
            shortest_len = now_len;
        }
    }
    return shortest_len;
}

int main()
{
    char s[1005];
    int result, i = 1;
    char *temp="fewftgewedddd" ;
    //scanf("%s", &s);
    while (s[i] != 0)
    {
        s[i]=temp+i;
        i++;
    }
    result = solution(s, i);
    printf("%d", result);
}