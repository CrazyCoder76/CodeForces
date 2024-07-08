#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<pair<int,int> > v;
	int tc;
	cin >> tc;
	while(tc--) {
		int n, m;
		v.clear();
		cin >> n >> m;
		for(int i = 0; i < n; i++) {
			int a, cnt1 = 0, cnt2 = 0, fg = 0;
			cin >> a;
			while(a) {
				int d = a % 10;
				if(d == 0 && fg == 0) cnt2 ++;
				else fg = 1;
				cnt1 ++;
				a /= 10;
			}
			v.push_back({cnt2, cnt1});
		}
		sort(v.begin(), v.end());
		int cnt = 0;
		for(int i = n - 1; i >= 0; i--) {
			if((n - i - 1) % 2 == 0) {
				cnt += v[i].second - v[i].first;
			}
			else {
				cnt += v[i].second;
			}
		}
		if(cnt > m) cout << "Sasha" << endl;
		else cout << "Anna" << endl;
	}
}
