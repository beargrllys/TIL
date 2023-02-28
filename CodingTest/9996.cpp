#include <bits/stdc++.h>

using namespace std;


int N;
string str, tmp;
string prefix, suffix;
int star;

int main() {
	cin >> N;
	cin >> str;
	star = str.find("*");
	
	prefix = str.substr(0, star);
	suffix = str.substr(star+1);

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		if (prefix.size() + suffix.size() > tmp.size()) {
			cout << "NE\n";
		}
		else {
			if (prefix == tmp.substr(0, prefix.size()) && suffix == tmp.substr(tmp.size() - suffix.size())) {
				cout << "DA\n";
			}
			else {
				cout << "NE\n";
			}
		}
		
	}
	return 0;
}
