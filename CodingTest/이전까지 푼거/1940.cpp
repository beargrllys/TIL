#include <bits/stdc++.h>

using namespace std;

int N, M, cnt;
vector<int> v;

int main() {
	int tmp;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}

	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (v[i] + v[j] == M) {
				cnt += 1;
			}
		}
	}
	cout << cnt;

	return 0;
}

//전형적인 조합문제, 수식 구현 코드 잘 숙지할 것.