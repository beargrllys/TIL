#include <iostream>

using namespace std;

#define DIFF 10

typedef struct
{
    int x; //row
    int y; //column
} redPatch;

int nMotorSpeedSetting = 35, vertex = 0, count = 0, row = 0, val, r = 0, c = 0, i, j, f, e;
int score = 0;
int S[6][6] = {{3, 1, 0, 1, 0, 0}, {0, -1, 0, -1, -1, 0}, {0, 1, 0, 0, 0, 0}, {0, 0, 0, -1, 1, 0}, {0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 0}};
int history[6][6], road[6][6];
redPatch redpatches[6];
int target_y = 4, target_x = 4,nowxpos=4, nowypos=4;

void redpatch_list()
{
    int index = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (S[i][j] == 1)
            {
                redpatches[index].x = j;
                redpatches[index].y = i;
                index++;
            }
            if (S[i][j] == -1)
            {
                road[i][j] = 9;
            }
        }
    }
    redpatches[index].x = 0;
    redpatches[index].y = 0;
}

int go_target(int x, int y, int rc)
{ //0: Row first 1: Col first
    if (x == target_x && y == target_y)
    {
        road[y][x] = 5;
        return 5;
    }
    if (S[y][x] == -1 || S[y][x] == 3)// the point is blue patch or arrive point
    {
        road[y][x] = 0;
        return 0;
    }
    if (rc) //check Col first
    {
        if (x != target_x) // not Arrive yet
        {
            int oneXStep = go_target(x + ((target_x - x) / abs(target_x - x)), y, 1);
            if (oneXStep == 0)
            { // meet blue patch
                road[y][x] = 0;
                return 0;
            }
            else
            {
                road[y][x] = 1;
                return 1;
            }
        }
        else if (y != target_y) // arrive
        {
            int oneYStep = go_target(x, y + ((target_y - y) / abs(target_y - y)), 1);
            if (oneYStep == 0)
            { // meet blue patch
                road[y][x] = 0;
                return 0;
            }
            else
            {
                road[y][x] = 1;
                return 1;
            }
        }
    }
    else //check Row first
    {
        if (y != target_y) // not Arrive yet
        {
            int oneYStep = go_target(x, y + ((target_y - y) / abs(target_y - y)), 0);
            if (oneYStep == 0)
            { // meet blue patch
                road[y][x] = 0;
                return 0;
            }
            else
            {
                road[y][x] = 1;
                return 1;
            }
        }
        else if (x != target_x) // arrive
        {
            int oneXStep = go_target(x + ((target_x - x) / abs(target_x - x)), y, 0);
            if (oneXStep == 0)
            { // meet blue patch
                road[y][x] = 0;
                return 0;
            }
            else
            {
                road[y][x] = 1;
                return 1;
            }
        }
    }
}

void set_target(int now_x, int now_y)
{
    int x, y, distance = 100, dist, index=0;
    for (int i = 0; i < 5; i++)
    {
        dist = abs(redpatches[i].x - now_x) + abs(redpatches[i].y - now_y);
        index = (dist > distance) ? index : i;
        distance = (dist > distance) ? distance : dist;
    }
    if((now_x == 1 && now_y == 2) && redpatches[index].y != 100){
        target_y = redpatches[1].y;
        target_x = redpatches[1].x;
        redpatches[1].x = 100;
        redpatches[1].y = 100;
    }else{
        target_y = redpatches[index].y;
        target_x = redpatches[index].x;
        redpatches[index].x = 100;
        redpatches[index].y = 100;
    }
    if(target_x == 100){
        target_y = 0;
        target_x = 0;
    }
}

void print(){
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            std::cout << road[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "----------------------" << endl;
}

void clearArry(){
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            road[i][j]=0;
            if(S[i][j] == -1){
                road[i][j]=9;
            }
        }
    }
}
void avoidBluePatch(){
    while(go_target(nowypos,nowxpos, 0) == 0 && go_target(nowypos,nowxpos, 1) == 0){
        road[nowxpos][nowypos] = 1;
        if(S[nowxpos][++nowypos] >= 0){}
        else if(S[++nowxpos][nowypos] >= 0){}
        else if(S[nowxpos][--nowypos] >= 0){}
        else if(S[--nowxpos][nowypos] >= 0){}
        road[nowxpos][nowypos] = 1;
    }
}

void getroad()
{
    int sideUp, Upside;
    for(int i=0; i < 6; i++){
        set_target(target_x, target_y);
        std::cout << nowxpos << "/" << nowypos << " -> ";
        std::cout << target_y << "/" << target_x << endl;
        sideUp = go_target(nowypos,nowxpos, 0);
        if(!sideUp){
            Upside = go_target(nowypos,nowxpos, 1);
        }
        if(!sideUp && !Upside){
            avoidBluePatch();
        }
        if(S[nowxpos][nowypos] == 1){
            road[nowxpos][nowypos] = 5;
        }
        else{
            road[nowxpos][nowypos] = 1;
        }
        nowxpos = target_y;
        nowypos = target_x;
        print();
        clearArry();
    }
}

int main()
{
    redpatch_list();
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            std::cout << S[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n----------------------" << endl;
    getroad();
}