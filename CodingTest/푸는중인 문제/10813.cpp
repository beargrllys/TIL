#include<iostream>

using namespace std;

int N,M;
int i,j;

int arr[110];

void swap(int* a, int* b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main()
{
	cin >> N >> M;

	for(int a = 1; a <= N; a++)
	{
		arr[a-1] = a;
	}

	for(int a = 0; a < M; a++)
	{
		cin >> i >> j;

		swap(&arr[i-1],&arr[j-1]);
	}

	for(int b = 1; b <= N; b++)
	{
		cout << arr[b-1] << " ";
	}
}