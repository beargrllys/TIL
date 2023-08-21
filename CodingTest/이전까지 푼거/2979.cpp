#include <bits/stdc++.h>

using namespace std;

int t[102];
int a, b, c;
int price = 0;
vector<vector<int>> v(3, vector<int>(2, 0));

int main() {
	cin >> a >> b >> c;
	for (int i = 0; i < 3; i++) {
		cin >> v[i][0] >> v[i][1];
		for (int j = v[i][0]; j < v[i][1]; j++) {
			t[j] += 1;
		}
	}
	for (int i = 0; i <= 100; i++) {
		if (t[i] == 1) {
			price += a;
		}
		else if (t[i] == 2) {
			price += (b*2);
		}
		else if (t[i] == 3) {
			price += (c*3);
		}
	}
	cout << price;
	return 0;
}
