#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

int c[200001];
int main() {
	int tc;
	cin >> tc;
	while(tc--) {
		int m, x;
		int money = 0;
		priority_queue<int> q;
		cin >> m >> x;
		for(int i = 0; i < m; i++)
			cin >> c[i];
		for(int i = 1; i < m; i++) {
			money += x;
			if(money >= c[i]) {
				q.push(c[i]);
				money -= c[i];
			}
			else if(!q.empty() && q.top() > c[i]) {
				money += q.top(); q.pop();
				money -= c[i];
				q.push(c[i]);
			}
		}
		cout << q.size() << endl;
	}
}
