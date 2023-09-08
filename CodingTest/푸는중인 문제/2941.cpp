#include<iostream>
#include<vector>


using namespace std;

vector<string> str = { "dz=", "c=", "c-", "d-", "lj", "nj", "s=", "z="};
string target;
int cnt = 0;

int main()
{
	cin >> target;

	for(int i = 0; i < (int)str.size(); i++)
	{
		while(int npos = target.find(str[i]) != string::npos)
		{
			target.erase(npos-1, (int)str[i].size());
			cnt+=1;
		}
	}
	cnt += target.size();

	cout << cnt;
}