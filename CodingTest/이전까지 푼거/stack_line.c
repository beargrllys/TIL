#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *up;
    int data;
};
// 구조체선언
struct Node *stack1 = NULL;
struct Node *stack2 = NULL;

//poped_stack == pop되는 stack의 pnum
struct Node *pop(struct Node *poped_stack, int what_stack)
{
    struct Node *temp_save = poped_stack; //타고 올라갈 변수
    struct Node *B_save = NULL;
    if (temp_save != NULL)
    {
        while (temp_save->up != NULL)
        { //멈추는 순간 temp_save가 최상위 노드
            B_save = temp_save;
            temp_save = temp_save->up;
        }
        if (B_save != NULL)
        {
            temp_save->up = NULL; //삽입시 혼선방지
            B_save->up = NULL;
        }
        else
        {
            if (what_stack == 1)
            {
                stack1 = NULL;
            }
            else
            {
                stack2 = NULL;
            }
        }
        return temp_save; //최상위 노드에 data반환
    }
    else
    { //스택이 비었다?
        return NULL;
    }
}

void insert(struct Node *inserted_stack, struct Node *inserted_node, int what_stack)
{
    struct Node *temp_save = inserted_stack; //끝단을 찾을 임시노드
    if (inserted_stack != NULL)
    {
        while (temp_save->up != NULL)
        { //up이 NULL인 노드
            temp_save = temp_save->up;
        }
        temp_save->up = inserted_node; //스택 연결 구간
    }
    else
    { //빈스택에 넣어야한다?
        if (what_stack == 1)
        {
            stack1 = inserted_node;
        }
        else
        {
            stack2 = inserted_node;
        }
    }
}

int top(struct Node *stack)
{
    struct Node *temp_save = stack; //타고 올라갈 변수
    if (temp_save != NULL)
    {
        while (temp_save->up != NULL)
        { //멈추는 순간 temp_save가 최상위 노드
            temp_save = temp_save->up;
        }
        temp_save->up = NULL;   //삽입시 혼선방지
        return temp_save->data; //최상위 노드에 data반환
    }
}

void show()
{
    struct Node *st1_temp = stack1;
    struct Node *st2_temp = stack2;
    //주소값을 따라가면서 NULL이 될때까지
    printf("|");
    while (st1_temp != NULL)
    { //맨위의 UP노드로 타고 올라갔는데 NULL이더라
        printf("%d  ", st1_temp->data);
        st1_temp = st1_temp->up;
    }
    printf("\n|");
    while (st2_temp != NULL)
    { //맨위의 UP노드로 타고 올라갔는데 NULL이더라
        printf("%d  ", st2_temp->data);
        st2_temp = st2_temp->up;
    }
    printf("\n\n");
}

void algorithm()
{
    struct Node *temp;
    if (top(stack1) < top(stack2) || stack2 != NULL) //스택 2에 있는게 더 커서 1로 옭겨야함
    {
        temp = pop(stack2, 2);
        insert(stack1, pop(stack2, 2), 1);
        algorithm();
        show();
    }
    else // 더작아서 안착하면 됨
    {
        insert(stack2, temp, 2);
        algorithm();
        show();
    }
    if (stack1 == NULL)
    {
        return 0;
    }
}

int main()
{
    int random_num[10] = {53, 75, 24, 68, 34, 63, 24, 64, 78, 56};
    //스택 충전
    for (int i = 0; i < 10; i++)
    {
        struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = random_num[i];
        new_node->up = NULL; //새로운 노드 포장하기
        insert(stack1, new_node, 1);
    }
    show();
    algorithm();
}