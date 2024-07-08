#include <bits/stdc++.h>
using namespace std;

int a[1001][1001];
int vis[1001][1001];
int n, m;
int bfs(int sx, int sy) {
	priority_queue<pair<int, int> > q;
	q.push({a[sx][sy], sx * m + sy});
	while(!q.empty()) {
		auto cur = q.top(); q.pop();
		int val = cur.first;
		int i = cur.second / m, j = cur.second % m;
		if(i == n - 1 && j == m - 1) return val;
		if(i < n - 1) {
			int gc = __gcd(val, a[i+1][j]);
				q.push({gc, {(i+1) *m + j}});
		}
		if(j < m - 1) {
			int gc = __gcd(val, a[i][j+1]);
				q.push({gc, {i * m+ j+1}});
		}
	}
}
int main() {
	int tc;
	cin >> tc;
	while(tc--) {
		cin >> n >> m;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> a[i][j];
		cout << bfs(0, 0) << endl;
	}
}
