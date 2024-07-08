#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

int a[1000001];
int b[1000001];
int main() {
	int tc;
	cin >> tc;
	while(tc--) {
		int n, m, k;
		map<int, int> dic_a, dic_b;
		multiset<int> s;
		cin >> n >> m >> k;
		for(int i = 0; i < n; i++)
			cin >> a[i];
		for(int i = 0; i < m; i++) {
			cin >> b[i];
			dic_b[b[i]] ++;
		}
		for(int i = 0; i < m; i++) {
			dic_a[a[i]]++;
			if(dic_a[a[i]] <= dic_b[a[i]])
				s.insert(a[i]);
		}
		int cnt = 0;
		if(s.size() >= k) cnt++;
		for(int i = m; i < n; i++) {
			dic_a[a[i-m]]--;
			if(dic_a[a[i-m]] < dic_b[a[i-m]]){
			    auto it = s.find(a[i-m]);
			    if (it != s.end()) {
			        s.erase(it);
			    }
			}
			dic_a[a[i]]++;
			if(dic_a[a[i]] <= dic_b[a[i]])
				s.insert(a[i]);
			
			if(s.size() >= k) {
				cnt++;
			}
		}
		cout << cnt << endl;
	}
}
