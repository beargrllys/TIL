/*
N <= 50인 격자가 있다. 격자에는 시작위치 * / 접근 불가 구역 x / 지점 1,2,3이 여러개(각각 최대 3개)씩 존재한다. 
시작위치 *에서 시작하여 주어진 1,2,3 순서대로 이동할때 이동거리가 가장 짧은 최단거리를 구하시오.

10
*.........
..X....1..
..XXXXX...
....3...X.
.2....1.X.
....XX..2.
....X.....
..X.3.1...
.XXXX..X..
..3...2...
*/

#include<iostream>
#include<queue>
#include<vector>
#include<limits>

using namespace std;

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
queue<pair<int, pair<int,int>>> q;

int N;
int m[52][52];
bool mb[52][52];
vector<pair<int,pair<int,int>>> dist;

void bfs(int target){

	while(q.empty() == false)
	{
		int dis = q.front().first;
		int tx 	= q.front().second.second;
		int ty 	= q.front().second.first;
		q.pop();
		mb[ty][tx] = true;

		int val = m[ty][tx];
		for(int i = 0; i < 4; i++)
		{
			int tmpy = ty + dy[i];
			int tmpx = tx + dx[i];
			if(tmpx < 0 || tmpx >= N || tmpy < 0 || tmpy >= N)
				continue;

			if(mb[tmpy][tmpx] == true)
				continue;
			

			if(m[tmpy][tmpx] == 'X')
				continue;

			if(m[tmpy][tmpx] == '.'){
				q.push({dis+1, {tmpy, tmpx}});
				continue;
			}

			if(m[tmpy][tmpx] == target){
				mb[tmpy][tmpx] = true;
				dist.push_back({dis, {tmpy, tmpx}});
				continue;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);
	memset(m, 0, sizeof(int)*N*N);
	string tmp;
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> tmp;
		for(int j = 0; j < N; j++){
			m[i][j] = tmp[j];
			if(m[i][j] == '*')
				dist.push_back({0,{i,j}});
		}
	}

	for(int i = 1; i <= 3; i++)
	{
		vector<pair<int,pair<int,int>>> tmp_dist(dist.size());
		copy(dist.begin(), dist.end(), tmp_dist.begin());
		dist.clear();
		for(int h = 0; h < tmp_dist.size(); h++)
		{
			memset(mb, false, sizeof(int)*N*N);
			q.push({tmp_dist[h].first, {tmp_dist[h].second.first, tmp_dist[h].second.second}});
			bfs('0' + i);
		}
	}

	int min_val = INT_MAX;
	for(int i = 0; i < dist.size(); i++)
	{
		if(dist[i].first < min_val)
			min_val = dist[i].first;
	}
	cout << min_val;
}