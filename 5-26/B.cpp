#include <cstdio>
#include <memory.h>
#include <iostream>
using namespace std;

int a[33];
int main() {
	int tc;
	cin >> tc;
	while(tc--) {
		int n;
		cin >> n;
		int cnt = 0;
		memset(a, 0, sizeof a);
		while(n) {
			a[cnt++] = n % 2;
			n /= 2;
		}
		for(int i = 0; i < cnt; i++) {
			if(a[i]) {
				int j = i + 1;
				while(a[j] != 0) j++;
				if(j > i + 1) {
					a[i] = -1;
					for(int k = i + 1; k < j; k++) a[k] = 0;
					a[j] = 1;
				}
			}
		}
		int ans = 0;
		for(int i = 0; i < 33; i++) {
			if(a[i]) ans = i;
		}
		cout << ans + 1 << endl;
		for(int i = 0; i <= ans; i++) {
			if(i) cout << " ";
			cout << a[i];
		}
		cout << endl;
	}
}
