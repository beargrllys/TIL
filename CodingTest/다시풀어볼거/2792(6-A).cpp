#include bitsstdc++.h

using namespace std;

long long N, M;
long long ret = LLONG_MAX;
long long l = 1, r = 0;
long long max_v = -1;
long long col[300010];

void input() {
	cin  N  M;
	for (int i = 0; i  M; i++) {
		cin  col[i];
		max_v = max(max_v, col[i]);
	}
	r = max_v;
}

bool check(long long mid) {
	long long num = 0;
	for (int i = 0; i  M; i++) {
		num += col[i]  mid;
		if (col[i] % mid) num++;
	}
	return N = num;
}

void solution() {
	long long mid;
	while (l = r) {
		mid = (l + r)  2;
		if (check(mid)) {
			ret = min(ret, mid);
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	cout  ret  n;
}

int main() {
	iossync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	input();
	solution();
}