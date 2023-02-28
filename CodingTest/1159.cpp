#include <bits/stdc++.h>

using namespace std;

map<char, int> m;
vector<char> vec;
int n;
string tmp;

int main() {
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		m[tmp[0]] += 1;
	}

	for (auto v : m) {
		if (v.second >= 5) {
			vec.push_back( v.first);
		}
	}

	if (vec.size() == 0) {
		cout << "PREDAJA";
	}
	else {
		sort(vec.begin(), vec.end());
		for (auto v : vec) {
			cout << v;
		}
	}
	return 0;
}
