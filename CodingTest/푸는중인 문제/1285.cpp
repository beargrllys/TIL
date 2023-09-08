#include<iostream>
using namespace std;

int N;
char mp[25][25];
int numR = 0, numC = 0;
int minT = 500;

int countT()
{
	int cnt = 0;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(mp[i][j] == 'T')
			{
				cnt += 1;
			}
		}
	}
	return cnt;
}

void Flip(int cnt)
{
	if(cnt == N*2)
	{
		return;
	}

	if(minT > countT())
		minT = countT();

	for(int i = 0; i < N; i++)
	{
		numR ^= (1 << i);
		for(int j = 0; j < N; j++)
		{
			if(mp[i][j] == 'H')
				mp[i][j] = 'T';
			else if(mp[i][j] == 'T')
				mp[i][j] = 'H';
		}
		Flip(cnt+1);
		numR ^= (1 << i);
		for(int j = 0; j < N; j++)
		{
			if(mp[i][j] == 'H')
				mp[i][j] = 'T';
			else if(mp[i][j] == 'T')
				mp[i][j] = 'H';
		}
	}
	for(int i = 0; i < N; i++)
	{
		numC ^= (1 << i);
		for(int j = 0; j < N; j++)
		{
			if(mp[j][i] == 'H')
				mp[j][i] = 'T';
			else if(mp[j][i] == 'T')
				mp[j][i] = 'H';
		}
		Flip(cnt+1);
		numC ^= (1 << i);
		for(int j = 0; j < N; j++)
		{
			if(mp[j][i] == 'H')
				mp[j][i] = 'T';
			else if(mp[j][i] == 'T')
				mp[j][i] = 'H';
		}
	}
}

int main()
{
	cin >> N;
	string str;
	for(int i = 0; i < N; i++)
	{
		cin >> str;
		for(int j = 0; j < N; j++)
		{
			mp[i][j] = str[j];
		}
	}
	minT = countT();
	Flip(0);
	cout << minT;
}