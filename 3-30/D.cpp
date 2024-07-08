#include <iostream>
using namespace std;

int p[1001][1001];
int mx[1001][1001];
int main() {
	int tc;
	cin >> tc;
	while(tc--) {
		int n, k;
		cin >> n >> k;
		for(int i = 0; i < n; i++)
			for(int j = i; j < n; j++)
				cin >> p[i][j];
		for(int i = 0; i < n; i++)
			for(int j = i; j < n; j++)
				mx[i][j] = max(mx[i-2][j-2] + p[i][j]);
	}
}
