#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <deque>
using namespace std;

int main() {
	int tc;
	cin >> tc;
	while(tc--) {
		int n;
		string s;
		cin >> n;
		cin >> s;
		for(int i = n; i >= 1; i--) {
			deque<int> q;
			int ans = 0;
			for(int j = 0; j <= n - i; j++) {
				int flag = s[j] -'0';
				if(!q.empty() && q.front() + i <= j) q.pop_front();
				flag += q.size();
				if(flag % 2 == 0) q.push_back(j);
			}
			for(int j = n - i + 1; j < n; j++) {
				int flag = s[j] -'0';
				if(!q.empty() && q.front() + i <= j) q.pop_front();
				flag += q.size();
				if(flag % 2 == 0) ans ++;
			}
			if(ans == 0) {
				cout << i << endl;
				break;
			}
		}
	}
}
