#include <iostream>
#include <set>
using namespace std;

using pii = pair<int, int>;

bool up_compare(const pii& a, const pii& b) 
{
	if(a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}
bool down_compare(const pii& a, const pii& b) 
{
	if(a.first == b.first)
		return a.second < b.second;
	return a.first > b.first;
}
bool left_compare(const pii& a, const pii& b) 
{
	if(a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}
bool right_compare(const pii& a, const pii& b) 
{
	if(a.second == b.second)
		return a.first < b.first;
	return a.second > b.second;
}

set<pii, decltype(up_compare)*> s_up(up_compare);
set<pii, decltype(down_compare)*> s_down(down_compare);
set<pii, decltype(left_compare)*> s_left(left_compare);
set<pii, decltype(right_compare)*> s_right(right_compare);

int main() {
	int tc;
	cin >> tc;
	while(tc--) {
		int a, b, n, m;
		cin >> a >> b >> n >> m;
		s_up.clear();
		s_down.clear();
		s_left.clear();
		s_right.clear();
		for(int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			s_up.insert({x, y});
			s_down.insert({x, y});
			s_left.insert({x, y});
			s_right.insert({x, y});
		}
		int alice = 0, bob = 0;
		int U, D, L, R;
		U = 1; L = 1; D = a; R = b;
		for(int i = 0; i < m; i++) {
			char ch;
			int k;
			cin >> ch >> k;
			if(ch == 'U') {
				U += k;
				auto it = s_up.begin();
				while(it != s_up.end() && it->first < U) {
					auto jt = it;
					it ++;
					s_down.erase(*jt);
					s_left.erase(*jt);
					s_right.erase(*jt);
					s_up.erase(jt);
					alice += i % 2 == 0;
					bob += i % 2;
				}
			}
			if(ch == 'D') {
				D -= k;
				auto it = s_down.begin();
				while(it != s_down.end() && it->first > D) {
					auto jt = it;
					it ++;
					s_up.erase(*jt);
					s_left.erase(*jt);
					s_right.erase(*jt);
					s_down.erase(jt);
					alice += i % 2 == 0;
					bob += i % 2;
				}
			}
			if(ch == 'L') {
				L += k;
				auto it = s_left.begin();
				while(it != s_left.end() && it->second < L) {
					auto jt = it;
					it ++;
					s_down.erase(*jt);
					s_up.erase(*jt);
					s_right.erase(*jt);
					s_left.erase(jt);
					alice += i % 2 == 0;
					bob += i % 2;
				}
			}
			if(ch == 'R') {
				R -= k;
				auto it = s_right.begin();
				while(it != s_right.end() && it->second > R) {
					auto jt = it;
					it ++;
					s_down.erase(*jt);
					s_left.erase(*jt);
					s_up.erase(*jt);
					s_right.erase(jt);
					alice += i % 2 == 0;
					bob += i % 2;
				}
			}
		}
		cout << alice << " " << bob << endl;
	}
}
