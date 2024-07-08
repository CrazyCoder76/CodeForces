#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int p[1000001];
vector<pair<int, int> > v;
int main() {
	int tc;
	cin >> tc;
	while(tc--) {
		int n, x, y;
		cin >> n >> x >> y;
		for(int i = 0; i < x; i++) cin >> p[i];
		sort(p, p+x);
		v.clear();
		int cnt = x + y - 2;
		int r = n - x - y;
		p[x] = p[0] + n;
		for(int i = 0; i < x; i++) {
			int gap = p[i+1] - p[i];
			if(gap > 1) v.push_back({gap % 2, gap});
		}
		sort(v.begin(), v.end());
		
		for(int i = 0; i < v.size(); i++) {
			int g = v[i].second;
			if(g % 2) {
				int mn = min(y, min(r, g/2));
				cnt += mn;
				y -= mn; r -= mn;
			}
			else {
				int mn = min(y, min(r, g/2));
				if(mn == g / 2) {
					cnt += mn;
					y -= mn - 1; r -= mn;
				}
				else if(mn == r) {
					cnt += mn;
					y -= mn; r -= mn;
				}
				else if(mn == y) {
					if(y + 1 == g / 2) {
						cnt += g / 2;
						y = 0; r -= g/ 2;
					}
					else {
						cnt += y;
						r -= y; y = 0;
					}
				}
			}
			if(r == 0) break;
		}
		cout << cnt << endl;
	}
}
