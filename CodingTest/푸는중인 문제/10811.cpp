#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec;

int N,M;
int i, j;

int main()
{
	cin >> N >> M;

	for(int a = 1; a <= N; a++)
	{
		vec.push_back(a);
	}

	for(int a = 0; a < M; a++)
	{
		cin >> i >> j;
		reverse(vec.begin()+(i-1), vec.begin()+(j));
	}
	
	for(int a = 0; a < N; a++)
	{
		cout << vec[a] << " ";
	}	
}