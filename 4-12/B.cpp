#include <bits/stdc++.h>
using namespace std;

int a[1000001];
int main() {
	int tc;
	cin >> tc;
	while(tc--) {
		int n;
		cin >> n;
		for(int i = 0; i < n; i++)
			cin >> a[i];
		int flag = 0;
		for(int i = 1; i < n; i++) if(a[i] != a[0]) flag = 1;
		if(flag == 0) cout << -1;
		else {
			int prev = -1, mn = 1e9;
			for(int i = 1; i < n; i++)
				if(a[i] != a[0]) {
					mn = min(mn, i - prev - 1);
					prev = i;
				}
			mn = min(mn, n - prev - 1);
			cout << mn;
		}
		cout << endl;
	}
}
