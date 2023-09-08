#include <iostream>
#include <string>

using namespace std;

int N;
int M;
string str;

int main() {
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		string ret = "";
		cin >> M >> str;

		for(int j = 0; j < str.size(); j++)
		{
			for(int k = 0; k < M; k++)
			{
				ret += str[j];
			}
		}
		cout << ret;
	}

	return 0;
}