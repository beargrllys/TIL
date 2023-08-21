
#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
vector<int> result;
int sum;
pair<int, int> ret;

//전체합 
// 2개 순서대로 지정 후 빼기
// 100이면 출력

//9C7 순열 계산

void solve() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < i; j++) {
            if ((sum - arr[i] - arr[j]) == 100) {
                ret.first = i;
                ret.second = j;
                return;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tmp = 0;
    for (int i = 1; i <= 9; i++) {
        cin >> tmp;
        arr.push_back(tmp);
    }

    sum = accumulate(arr.begin(), arr.end(), 0);

    solve();

    for (int i = 0; i < 9; i++) {
        if (i == ret.first || i == ret.second) 
            continue;
        else
            result.push_back(arr[i]);
    }
    sort(result.begin(), result.end());
    for (int i = 0; i < 7; i++) {
        cout << result[i]  << "\n";
    }
}
