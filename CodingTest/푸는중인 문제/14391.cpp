#include <iostream>
#include <algorithm> 

using namespace std;

int N,M;
int mp[5][5];
int ret = -1;

int main()
{
	string str;

	cin >> N >> M;

	for(int i = 0; i < N; i++)
	{
		cin >> str;
		for(int j = 0; j < M; j++)
		{
			mp[i][j] = str[j] - '0';
		}
	}

	for(int s = 0; s < (1 << (N * M)); s++)
	{
		int sum = 0;
		for(int i = 0; i < N; i++)
		{
			int cur = 0;
			for(int j = 0; j < M; j++)
			{
				int k = i * M + j;
				if((s & (1 << k)) == 0)
				{
					cur = cur * 10 + mp[i][j];
				}
				else
				{
					sum += cur;
					cur = 0;
				}
			}
			sum += cur;
		}
		for(int j = 0; j < M; j++)
		{
			int cur = 0;
			for(int i = 0; i < N; i++)
			{
				int k = i * M + j;
				if((s & (1<<k)) != 0)
				{
					cur = cur * 10 + mp[i][j];
				}
				else
				{
					sum += cur;
					cur = 0;
				}
			}
			sum += cur;
		}
		ret = max(ret, sum);
	}
	cout << ret << "\n";
	return 0;
}