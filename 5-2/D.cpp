#include <iostream>
using namespace std;

long long p[200001];
long long a[200001];
int main() {
	int tc;
	cin >> tc;
	while(tc--) {
		int n, k, p1, p2;
		cin >> n >> k >> p1 >> p2;
		for(int i = 1; i <= n; i++) cin >> p[i];
		for(int i = 1; i <= n; i++) cin >> a[i];
		long long point1, point2;
		long long max = -1, max_sum = 0, sum = 0, pos = p1;
		for(int i = 0; i < min(k, n); i++) {
			if(max < a[pos]) {
				max = a[pos];
				if(max_sum < sum + a[pos] * (k - i)) {
					max_sum = sum + a[pos] * (k - i);
				}
			}
			sum += a[pos];
			pos = p[pos];
		}
		point1 = max_sum;
		max = -1, max_sum = 0, sum = 0, pos = p2;
		for(int i = 0; i < min(k, n); i++) {
			if(max < a[pos]) {
				max = a[pos];
				if(max_sum < sum + a[pos] * (k - i)) {
					max_sum = sum + a[pos] * (k - i);
				}
			}
			sum += a[pos];
			pos = p[pos];
		}
		point2 = max_sum;
		if(point1 == point2) cout << "Draw";
		else if(point1 < point2) cout << "Sasha";
		else cout << "Bodya";
		cout << endl;
	}
}
