#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, K;
int main(void)

{
        ios_base::sync_with_stdio(0);
        cin.tie(0); 
        cin >> N >> M >> K;
        if (M + K - 1 <= N && N <= M * K)
        {
                 vector<int> arr(N);
                 for (int i = 0; i < N; i++)
                         arr[i] = i + 1;
                 int idx = 0;
                 for (int i = 1; i <= M; i++)
                 {
                         int temp = min(idx + K, N - M + i);
                         reverse(arr.begin() + idx, arr.begin() + temp);
                         idx = temp;
                 }
                 for (int i = 0; i < N; i++)

                         cout << arr[i] << " ";
                 cout << "\n";
        }
        else
                 cout << -1 << "\n";
        return 0;
}