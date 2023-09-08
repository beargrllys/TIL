#include<iostream>

using namespace std;

int N, L;
int mp[110][110];

int part[110];
bool visited[110];

bool check()
{
	memset(visited, false, sizeof(bool)*110);
	int now;
	for(int i = 0; i < N-L; i++)
	{
		now = part[i];
		if(now > part[i+1])
		{
			for(int j = i+1; j <= i + L; j++)
			{
				if(j >= N)
				{
					cout << "1. " << j << N << "\n";
					return false;
				}
				if(part[j] != now-1 || visited[j] == true)
				{
					cout << "2. " << part[j] << now-1 << "\n";
					return false;
				}
			}
			for(int j = i+1; j <= i + L; j++)
				visited[j] = true;
		}
	}

	for(int i = N-1; i >= L-1; i--)
	{
		now = part[i];
		if(now > part[i-1])
		{
			for(int j = i-1; j >= i - L; j--)
			{
				if(j < 0)
				{
					cout << "3. " << j << "\n";
					return false;
				}
				if(part[j] != now-1 || visited[j] == true)
				{
					cout << "4. " << part[j] << now-1 << "\n";
					return false;
				}
			}
			for(int j = i-1; j >= i - L; j--)
				visited[j] = true;
		}
	}
	cout << "\n";
	for(int i = 0; i < N; i ++ )
		cout << part[i] << " ";
	cout << "\n";
	return true;
}

int main()
{
	int cnt = 0;
	cin >> N >> L;
	for(int i = 0 ; i < N; i++)
	{
		for(int j = 0 ; j < N; j++)
		{
			cin >> mp[i][j];
		}
	}

	/*for(int i = 0 ; i < N; i++)
	{
		for(int j = 0 ; j < N; j++)
		{
			part[j] = mp[i][j];
		}
		if(check() == true)
			cnt += 1;
	}

	for(int i = 0 ; i < N; i++)
	{
		for(int j = 0 ; j < N; j++)
		{
			part[j] = mp[j][i];
		}
		if(check() == true)
			cnt += 1;
	}*/

	cout << cnt;
}