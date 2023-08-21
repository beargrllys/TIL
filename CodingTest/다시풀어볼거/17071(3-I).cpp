#include <bits/stdc++.h>
using namespace std;

int visited[1000010];
int t[1000010];

int os, ys;

void input() {
	cin >> os >> ys;
}

int move(int t) {
	int acc = 0;
	for(int a = 1; a <= t ; a++) {
		acc += a;
	}
	return acc;
}

int bfs() {
	queue<pair<int,int>> q;
	q.push({ os , 1});
	visited[os] = 1;
	t[os] = 1;
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		int yscur = ys + move(cur.second-1);
		q.pop();
		if (cur.first < 0 || cur.first > 500000) {
			continue;
		}
		if (yscur < 0 || yscur > 500000) {
			continue;
		}
		if (cur.first == yscur) {
			return cur.second - 1;
		}
		if (!visited[cur.first + 1]) {
			q.push({ cur.first + 1 , cur.second + 1});
		}
		if (!visited[cur.first - 1]) {
			q.push({ cur.first - 1 , cur.second + 1 });
		}
		if (!visited[cur.first * 2]) {
			q.push({ cur.first * 2 , cur.second + 1 });
		}
	}
	return -1;
}

void solution() {
	cout << bfs();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	input();
	solution();
}