#include<iostream>
#include<cstring>

using namespace std;

int N;

int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};
int plant[12][12];
bool visited[12][12];

int min_p = 3000;

void Track(int cnt, int p)
{
	if(cnt == 3)
	{
		if(min_p > p)
			min_p = p;
		return;
	}
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			bool is_able = true;
			if(visited[i][j] == true)
				continue;
			for(int h = 0 ; h < 4; h++)
			{
				if(i+dy[h] < 0 || i+dy[h] >= N || j+dx[h] < 0 || j+dx[h] >= N)
					is_able = false;
				if(visited[i+dy[h]][j+dx[h]] == true)
					is_able = false;
			}
			if(is_able == true)
			{
				visited[i][j] = true;
				int F_p = plant[i][j];
				for(int h = 0 ; h < 4; h++)
				{
					visited[i+dy[h]][j+dx[h]] = true;
					F_p += plant[i+dy[h]][j+dx[h]];
				}
				Track(cnt + 1, p + F_p);
				visited[i][j] = false;
				for(int h = 0 ; h < 4; h++)
				{
					visited[i+dy[h]][j+dx[h]] = false;
				}
			}
		}
	}


}

int main()
{
	cin >> N;
	for(int i = 0 ; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			cin >> plant[i][j];
		}
	}
	memset(visited, false, sizeof(bool)*N*N);

	Track(0, 0);

	cout << min_p;
}