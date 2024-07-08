#include <bits/stdc++.h>
using namespace std;

int a[300001];
int m[300001];
int main() {
	int tc;
	cin >> tc;
	while(tc--) {
		int n, k;
		cin >> n >> k;
		memset(m, 0, sizeof m);
		for(int i = 0; i < n; i++) cin >> a[i];
		for(int i = 0; i < n; i++) {
			int x;
			cin >> x;
			m[abs(x)] += a[i];
		}
		long long res = 0;
		int flag = 0;
		for(int i = 1; i <= n; i++) {
			res += k;
			if(m[i] > res) {
				flag = 1; break;
			}
			res -= m[i];
		}
		if(flag) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
}
