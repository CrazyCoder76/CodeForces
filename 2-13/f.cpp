#include <bits/stdc++.h>
using namespace std;

int a[200001];
int p[200001];
int get_parent(int u) {
	if(p[u] == -1) return u;
	return p[u] = get_parent(p[u]);
}
int main() {
	int tc;
	cin >> tc;
	while(tc--) {
		int n, k;
		cin >> n >> k;
		memset(p, 0xff, sizeof p);
		int flag = 0;
		for(int i = 0; i < k; i++) {
			for(int j = 0; j < n; j++) {
				cin >> a[j];
				if(j >= 2) {
					if(p[a[j]] == -1) p[a[j]] = get_parent(a[j-1]);
					else if(get_parent(a[j]) != get_parent(a[j-1])) flag = 1;
				}
			}
		}
		if(flag == 1) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
}
