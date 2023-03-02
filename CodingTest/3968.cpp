#include <bits/stdc++.h>

using namespace std;

int N;
string str;
bool nothing = true;
int cnt;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		stack<int> stk;
		for (int i = 0; i < str.size(); i++) {
			if (stk.empty()) {
				stk.push(str[i]);
			}
			else {
				if (stk.top() == str[i]) {
					stk.pop();
				}
				else {
					stk.push(str[i]);
				}
			}
		}
		if (stk.empty()) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}

//뭔지 모르겠을깨는 수직으로 돌려보고 -> 스택,  하나더 늘려봐라
//아이디어를 잘 생각하자