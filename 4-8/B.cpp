#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	int tc;
	cin >> tc;
	map<long long, int> m;
	while(tc--) {
		int n, d, c;
		cin >> n >> c >> d;
		long long mn = -1;
		m.clear();
		for(int i = 0; i < n * n; i++) {
			int t;
			cin >> t;
			m[t]++;
			if(mn > t || mn == -1) mn = t;
		}
		
		int flag = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++) {
				long long t = mn + c * i + d * j;
				if(m[t] > 0) m[t]--;
				else flag = 1;
			}
		
		cout << (flag ? "NO" : "YES") << endl;
	}
}
