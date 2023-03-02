#include <bits/stdc++.h>

using namespace std;

string N, str, streverse;
int oddCnt;
char odd = '\0';
int alp[26];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;

	for (int i = 0; i < N.size(); i++) {
		alp[N[i] - 'A'] += 1;
	}
	for (int i = 0; i < 26; i++) {
		if (alp[i] % 2 == 1) {
			oddCnt += 1;
			odd = i + 'A';
		}
	}
	if (oddCnt > 1) {
		cout << "I'm Sorry Hansoo\n";
		return 0;
	} 
	for (int i = 0; i < 26; i++) {
		alp[i] = alp[i] / 2;
		for (int j = 0; j < alp[i]; j++) {
			str += i + 'A';
		}
	}

	cout << str;
	if (odd != '\0')
		cout << odd;
	reverse(str.begin(), str.end());
	cout << str;
	
	return 0;
}

//reverse 사용법: reverse(대상.begin(), 대상.end())
//홀수 짝수 판별법 : 변수 & 1 == 1 => 홀수  /  변수 & 1 == 0 => 짝수
//문자열 앞에 문자 붙히기 = ret = 'Char' + ret;
//문자열 중앙에 문자