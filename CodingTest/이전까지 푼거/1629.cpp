#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll a, b, c;

ll go(ll a, ll b) {
	if (b == 1) return a % c;

	ll ret = go(a, b / 2);
	ret = (ret * ret) % c;
	if (b % 2) ret = (ret % a) % c;
	return ret;
}

int main() {
	cin >> a >> b >> c;
	cout << go(a, b) << "\n";
	return 0;
}

//큰수의 계산이나 능력밖의 계산을 요구할때는 모듈러 연산을 이용하라
