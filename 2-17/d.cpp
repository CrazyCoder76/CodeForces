#include <bits/stdc++.h>
using namespace std;

void chkmin(int& a, int b) {
	if(a > b) a = b;
}

int a[101][101];
int b[101][101];
int c[101][101];
int main() {
	int tc;
	cin >> tc;
	while(tc--) {
		int n;
		string str;
		cin >> n;
		cin >> str;
		memset(a, 0, sizeof a);
		memset(b, 0, sizeof b);
		memset(c, 0, sizeof c);
		for(int i = 0; i < n; i++) {
			a[i][i] = b[i][i] = c[i][i] = str[i] - '0';
		}
		for(int i = 2; i <= n; i++)
			for(int j = 0; j + i <= n; j++) {
			}
		int cnt = 0;
		for(int i = 0; i < n; i++)
			for(int j = i; j < n; j++) {
				cnt += a[i][j];
				cout << i << "," << j << "-" << a[i][j] << "," << b[i][j] << "," << c[i][j] << endl;
			}
		cout << cnt << endl;
	}
}
