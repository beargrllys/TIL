#include <bits/stdc++.h>

using namespace std;


string tmp;
string rot13;

int main() {
	getline(cin, tmp);
	
	for (int i = 0; i < tmp.length(); i++) {
		if (tmp[i] >= 'A' && tmp[i] <= 'Z')
			rot13 += (((tmp[i] - 'A') + 13) % 26) + 'A';
		else if (tmp[i] >= 'a' && tmp[i] <= 'z')
			rot13 += (((tmp[i] - 'a') + 13) % 26) + 'a';
		else
			rot13 += tmp[i];
	}

	cout << rot13;
	return 0;
}
