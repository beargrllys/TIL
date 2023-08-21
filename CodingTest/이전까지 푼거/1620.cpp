#include <bits/stdc++.h>

using namespace std;

int N, M;
map<string, int> m;
string v[100004];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;

	string tmp;
	for (int i = 1; i <= N; i++) {
		cin >> tmp;
		m[tmp] = i;
		v[i] = tmp;
	}
	string str;
	for (int i = 0; i < M; i++) {
		cin >> str;
		if (atoi(str.c_str())) {
			cout << v[stoi(str)] << "\n";
		}
		else {
			cout << m[str] << "\n";
		}
	}
	return 0;
}

//팁1 : atoi() : 스트링을 인트로 변환가능 여부 -> 가능: (변환된 값), 불가능 : 0
//팁2 : 서로 다른 자료형을 오고가며 검색해