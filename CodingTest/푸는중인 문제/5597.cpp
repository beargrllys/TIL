#include <iostream>

using namespace std;

bool check[30];

int n;
int main()
{


	for(int i = 0; i <28; i++)
	{
		cin >> n;

		check[n] = true;
	}

	for(int i = 1; i <= 30; i++)
	{
		if(check[i] == false)
		{
			cout << i << "\n";
		}

	}
}