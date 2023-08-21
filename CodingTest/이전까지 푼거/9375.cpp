#include <bits/stdc++.h>

using namespace std;

int N, M;
string a, b;

map<string, int> m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int cnt = 1;
		cin >> M;
		for (int j = 0; j < M; j++) {
			cin >> a >> b;
			m[b] += 1;
		}
		for (auto it = m.begin(); it != m.end(); it++) {
			cnt *= (it->second + 1);
		}
		cout << cnt - 1 << "\n";
		m.clear();
	}
	return 0;
}

//경우의수 구하기 : 적어도 한개는 입고 나가야한다 -> 모든 경우의수 -1
//공백도 입력에 구분자다 됨을 잊지 마라
