#include <iostream>

using namespace std;

int R,C,K;
int mp[10][10];
bool visited[10][10];

int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};

int cnt = 0;

void dfs(int y, int x, int dist)
{
	if(mp[y][x] == 'T')
		return;
	if(y == 0 && x == C-1)
	{
		cout << y << " / " << x << " / " << dist<<"\n";
		if(dist == K)
		{
			cnt += 1;
		}
		return;
	}
	for(int i = 0; i < 4; i++)
	{
		if(y+dy[i] < 0 || y+dy[i] >= R || x+dx[i] < 0 || x+dx[i] >= C)
			continue;
		if(visited[y+dy[i]][x+dx[i]] == true)
			continue;
		visited[y+dy[i]][x+dx[i]] = true;
		dfs(y+dy[i], x+dx[i], dist+1);
		visited[y+dy[i]][x+dx[i]] = false;
	}
}

int main()
{
	char str[12];
	cin >> R >> C >> K;
	for(int i = 0; i < R; i++)
	{
		cin >> str;
		for(int j = 0; j < C; j++)
		{
			mp[i][j] = str[j];
		}
	}
	visited[R-1][0] = true;
	dfs(R-1, 0, 1);

	cout << cnt;

	return 0;
}