#include <cstdio>
#include <algorithm>

using namespace std;

int max(int a, int b) { return a > b ? a : b; }

int main() {
    int N, i, ans = 0;
    
    scanf("%d", &N);
    int arr[N];

    for (i = 0; i < N; i++) scanf("%d", &arr[i]);
    sort(arr, arr+N);
    for (i = 0; i < N; i++) ans = max(ans, arr[i]*(N-i));
    printf("%d\n", ans);

    return 0;
}