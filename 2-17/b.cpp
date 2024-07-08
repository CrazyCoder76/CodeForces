#include <bits/stdc++.h>
using namespace std;

int a[100001];
int main() {
	int tc;
	cin >> tc;
	while(tc--) {
		int n;
		cin >> n;
		int st = 1, ed = n;
		for(int i = 1; i <= n; i++) {
			if(i % 2 == 1) a[i] = st++;
			else a[i] = ed--;
		}
		for(int i = 1; i <= n; i++) {
			if(i > 1) cout << " ";
			cout << a[i];
		}
		cout << endl;
	}
}
