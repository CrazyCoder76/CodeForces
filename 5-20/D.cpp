#include <cstdio>
#include <iostream>
using namespace std;

char str[1000001];
char ans[1000001];
int main() {
	int tc;
	cin >> tc;
	while(tc--) {
		int n;
		char ch;
		cin >> n;
		cin >> str;
		int N = 0, E = 0, S = 0, W = 0;
		for(int i = 0; i < n; i++) {
			if(str[i] == 'N') N++;
			else if(str[i] == 'E') E++;
			else if(str[i] == 'S') S++;
			else W++;
		}
		int V = N - S, H = E - W;
		if(V % 2 || H % 2) {
			cout << "NO" << endl;
			continue;
		}
		V /= 2; H /= 2;
		int fg = 1;
		if(V == 0 && H == 0) fg = 0;
		int cnt = 0;
		for(int i = 0; i < n; i++) {
			if(fg == 0 && str[i] == 'S') {
				V++;
				ans[i] = 'H';
				fg = 1;
			}
			else if(fg == 0 && str[i] == 'N') {
				V--;
				ans[i] = 'H';
				fg = 1;
			}
			else if(fg == 0 && str[i] == 'W') {
				H++;
				ans[i] = 'H';
				fg = 1;
			}
			else if(fg == 0 && str[i] == 'E') {
				H--;
				ans[i] = 'H';
				fg = 1;
			}
			else if(V < 0 && str[i] == 'S') {
				V++;
				ans[i] = 'H';
			}
			else if(V > 0 && str[i] == 'N') {
				V--;
				ans[i] = 'H';
			}
			else if(H < 0 && str[i] == 'W') {
				H++;
				ans[i] = 'H';
			}
			else if(H > 0 && str[i] == 'E') {
				H--;
				ans[i] = 'H';
			}
			else {
				ans[i] = 'R';
				cnt ++;
			}
		}
		if(cnt == 0 || cnt == n || V != 0 || H != 0) {
			cout << "NO" << endl;
			continue;
		}
		ans[n] = 0;
		cout << ans << endl;
	}
}
