#include <cstdio>

int main() {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n - 2; i++)
			printf("%d %d\n", 1, i+1);
		printf("%d %d\n", n-1, 1);
		printf("%d %d\n", n, n);
	}
}
