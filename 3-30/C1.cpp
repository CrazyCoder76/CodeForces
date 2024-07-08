#include <iostream>
#include <algorithm>
using namespace std;

int p[1000001];
int main() {
	int tc;
	cin >> tc;
	while(tc--) {
		int n, x, y;
		cin >> n >> x >> y;
		for(int i = 0; i < x; i++) cin >> p[i];
		sort(p, p+x);
		int cnt = 0;
		p[x] = p[0] + n;
		for(int i = 0; i < x; i++) {
			if(p[i+1]-p[i] == 2) cnt++;
		}
		cnt += x - 2;
		cout << cnt << endl;
	}
}
