#include<iostream>

using namespace std;

int N,M;
int i,j,k;

int arr[100];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for(int a = 0; a < M; a++)
	{
		cin >> i >> j >> k;

		for(int b = i-1; b < j; b++)
		{
			arr[b] = k;
		}
	}

	for(int a = 0; a < N; a++)
	{
		cout << arr[a] << " ";
	}
}