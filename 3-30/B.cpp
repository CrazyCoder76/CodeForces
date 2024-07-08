#include <iostream>
#include <set>
using namespace std;

int a[1000001];
int p[1000001];
int main() {
	int tc;
	cin >> tc;
	while(tc--) {
		int n;
		cin >> n;
		set<int> s;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			s.insert(i);
		}
		for(int i = 0; i < n; i++) {
			auto it = s.begin();
			if(s.size() == 1) {
				p[i] = *it;
			}
			else {
				int min0 = *it; it++;
				int min1 = *it;
				if(min1 - min0 == a[i]) {
					p[i] = min0;
					s.erase(min0);
				}
				else {
					p[i] = min0 - a[i];
					s.erase(p[i]);
				}
			}
		}
		for(int i = 0; i < n; i++) {
			if(i) cout << " ";
			cout << p[i];
		}
		cout << endl;
	}
}
