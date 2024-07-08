#include <cstdio>
#include <iostream>
#include <map>
using namespace std;

int a[1001];
int main() {
	int tc;
	cin >> tc;
	while(tc--) {
		int n, k;
		map<int, int> cnt;
		cin >> n >> k;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			cnt[a[i]]++;
		}
		int flag = 0;
		for(auto it: cnt)
			if(it.second >= k) flag = 1;
		if(flag) cout << k - 1 << endl;
		else cout << n << endl;
	}
}
