#include <bits/stdc++.h>
using namespace std;

long long mod = 998244353;

long long modExp(long long base, long long exp) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

// Function to compute x / y % MOD
long long modDiv(long long x, long long y) {
    // Compute y^(-1) mod MOD using Fermat's Little Theorem
    long long y_inv = modExp(y, mod - 2);
    // Compute (x * y^(-1)) mod MOD
    return (x * y_inv) % mod;
}

long long GetN(int n, int k) {
	long long ans = 1;
	n = n + k - 1;
	for(int i = 0; i < k; i++) {
		ans = (ans * (n - i)) % mod;
		ans = modDiv(ans, k - i);
	}
	return ans;
}
int main() {
	int tc;
	cin >> tc;
	while(tc--) {
		int c0, c1, c2, c3;
		cin >> c0 >> c1 >> c2 >> c3;
		if(abs(c0 - c1) > 1) cout << 0 << endl;
		else if(c0 == 0 && c1 == 0) {
			if(c2 > 0 && c3 > 0) cout << 0 << endl;
			else cout << 1 << endl;
		}
		else if(c0 == c1) {
			long long ans = (GetN(c0 + 1, c2) * GetN(c0, c3) % mod) + (GetN(c0, c2) * GetN(c0 + 1, c3) % mod);
			cout << ans % mod << endl;
		}
		else {
			int n = max(c0, c1);
			long long ans = GetN(n, c2) * GetN(n, c3);
			cout << ans % mod << endl;
		}
	}
}
