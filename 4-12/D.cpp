#include <bits/stdc++.h>
using namespace std;

int a[5001];
int dp[5001];
int dp1[5001];
int p2[5001];
int mod = 998244353;
int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	p2[0] = 1;
	for(int i = 1; i <= 5000; i++) p2[i] = (p2[i - 1] * 2) % mod;
	dp[0] = dp1[0] = a[0];
	for(int i = 1; i < n; i++) {
		int t = (p2[i] * a[i] + dp[i-1]) % mod;
		dp1[i] = (1LL * t - dp1[i-1]) % mod;
		dp[i] = (1LL * dp[i-1] + dp1[i]) % mod;
		
		cout << dp[i] << endl;
	}
	cout << dp[n-1] << endl;
}
