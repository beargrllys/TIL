//2023.08.21

#include <iostream>
#include <vector>

using namespace std;

int val = -1, idx = -1;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int tmp;
	for(int i = 0; i < 9; i++){
		cin >> tmp;
		if(val < tmp)
		{
			val = tmp;
			idx = i+1;
		}
	}

	cout << val << "\n" << idx;
}