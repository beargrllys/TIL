#include <iostream>
#include <vector>

using namespace std;

int N;
int tmp;
int mx = -1;

vector<int> vec;

float fl = 0;

int main()
{
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> tmp;
		if(mx < tmp)
			mx = tmp;

		vec.push_back(tmp);
	}

	for(int i = 0; i < N; i++)
	{
		fl += (float) vec[i]/mx*100;

	}
	cout << mx << "\n";
	cout << (float)fl/N;
}