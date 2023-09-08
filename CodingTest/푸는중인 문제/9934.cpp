#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int N;
int vec[2000];
vector<int> tree[14];

void trak(int s, int e, int dep)
{
	if(s > e) return;
	if(s == e) 
	{
		tree[dep].push_back(vec[s]);
		return;
	}
	int mid = (s+e)/2;
	tree[dep].push_back(vec[mid]);
	trak(s,mid-1, dep+1);
	trak(mid+1, e, dep+1);
	return;
}

int main()
{
	cin >> N;
	int end = (int)pow(2,N)-1;
	for(int i = 0 ; i< end; i++)
	{
		cin >> vec[i];
	}

	trak(0, end, 1);

	for(int i = 1; i <= N; i++)
	{
		for(int j : tree[i])
		{
			cout << j << " ";
		}
		cout << "\n";
	}

	return 0;

}