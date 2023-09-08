/*
은행이용객의 비밀번호를 연산할때는 고객마다 A,B,C 값을 가진다. 이때 은행은 고객의 비밀번호를 검증하기 위해서 이미 주어진 X,Y값을 가지고 있다. 은행의 비밀번호 검증법은 다음과 같다. (AX^2 + BX + C)%999983 = Y에서 Y가 같으면 비밀번호는 맞다고 처리된다. 단 (X-3)~(X+3)사이의 7개 값을 연산한 값과 같아도 맞다고 처리한다. X범위에 따른 Y의 대입 가능 값을 출력하라

X = 12 

12
3
283 4759 390
12 38 20
974859 284763 473853 
*/

#include <iostream>
#include <vector>

using namespace std;

int initX, N;
int A,B,C;

vector <long long> ret_set;

int main()
{
	cin >> initX >> N;
	long long ret = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> A >> B >> C;
		for(int X = initX - 3; X <= initX + 3; X++)
		{
			ret += A * pow(X,2);
			ret += (B * X);
			ret += C;

			ret_set.push_back(ret % 999983);
			ret = 0;
		}

		for(int j = 0; j < ret_set.size(); j++){
			cout << ret_set[j] << " ";
		}
		cout << "\n";
		ret_set.clear();
	}

}