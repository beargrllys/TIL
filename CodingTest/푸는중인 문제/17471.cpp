#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int N;
int people[12];
vector<vector<int>> node(12,std::vector<int>());

queue<int> q;

int gap = 1100;

bool bfs(int s)
{
	int visited = 0;
	int reg1 = -1, reg2 = -1;
	for(int i = 0; i < N; i++){
		if(reg1 == -1 && (s & (1 << i)) == 0)
		{
			reg1 = i;
		}
		if(reg2 == -1 && (s & (1 << i)) != 0)
		{
			reg2 = i;
		}
	}

	if(reg1 != -1)
	{
		q.push(reg1);
		while(!q.empty())
		{
			int f = q.front();
			q.pop();
			cout << q.front() << "\n";
			visited = visited | (1 << f);
			for(int i = 0; i < (int)node[f].size(); i++)
			{
				if((visited & (1 << (node[f][i]-1))) != 0)
					continue;
				if((s & (1 << (node[f][i]-1))) != 0)
					continue;
				q.push(node[f][i]);
			}
		}
	}

	if(reg2 != -1)
	{
		q.push(reg2);
		visited = visited | (1 << reg2);
		while(!q.empty())
		{
			int f = q.front();
			q.pop();
			visited = visited | (1 << f);
			for(int i = 0; i < (int)node[f].size(); i++)
			{
				if(visited & (1 << (node[f][i]-1)) != 0)
					continue;
				if((s & (1 << (node[f][i]-1))) == 0)
					continue;
				q.push(node[f][i]);
			}
		}
	}

	if(visited == ((1 << N)-1))
		return true;
	else
		return false;
}

int main()
{
	cin >> N;
	for(int i = 0 ; i < N; i++)
	{
		cin >> people[i];
	}
	for(int i = 0; i < N; i++)
	{
		int conn;
		cin >> conn; 
		for(int j = 0; j < conn; j++)
		{
			int val;
			cin >> val; 
			node[i].push_back(val);
		}
	}

	for(int s = 0; s < (1 << N); s++)
	{
		if(bfs(s) == false)
			continue;

		int sum1 = 0;
		int sum2 = 0;
		for(int i = 0; i < N; i++)
		{
			if((s & (1 << i)) == 0)
			{
				sum1 += people[i];
			}
			else
			{
				sum2 += people[i];
			}
		}
		gap = min(gap , abs(sum1 - sum2));
	}
	if(gap == 1100)
		cout << -1;
	else
		cout <<  gap;

	return 0;
}