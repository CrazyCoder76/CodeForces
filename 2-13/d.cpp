#include <bits/stdc++.h>
using namespace std;

int a[200001];
int main() {
	int tc;
	map<pair<int, int>, int> dic;
	cin >> tc;
	while(tc--) {
		int n, x, y;
		cin >> n >> x >> y;
		for(int i = 0; i < n; i++)
			cin >> a[i];
		dic.clear();
		dic[{a[0] % x, a[0] % y}] = 1;
		long long cnt = 0;
		for(int i = 1; i < n; i++) {
			int dx = x - (a[i] % x), dy = a[i] % y;
			if(dx == x) dx = 0;
			cnt += dic[{dx, dy}];
			dic[{a[i] % x, a[i] % y}] ++;
		}
		cout << cnt << endl;
	}
}
