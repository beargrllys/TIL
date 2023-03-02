#include <bits/stdc++.h>

using namespace std;


int N, K;
int sum[100010];
int ret = -10000004;

int main() {
	cin >> N;
	cin >> K;

	int tmp;
	for (int i = 1; i <= N; i++) {
		cin >> tmp;
		sum[i] = sum[i - 1] + tmp;
	}

	for (int i = K; i <= N; i++) {
		ret = max(ret, sum[i] - sum[i-K]);
	}
	cout << ret;
	return 0;
}
