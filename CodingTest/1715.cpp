#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n;
    int sum=0;
    cin >> n;

    priority_queue<int, vector<int>, greater<int> > pq;

    for (int i=0; i<n; i++){
        int temp;
        cin >> temp;
        pq.push(temp);
    }

    if(pq.size() == 1){
        cout << 0 <<endl;
        return 0;
    }

    while(!pq.empty()){
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        sum += (a+b);
        if(pq.empty()){
            break;
        }
        pq.push(a+b);
    }

    cout << sum <<endl;
    return 0;
}
