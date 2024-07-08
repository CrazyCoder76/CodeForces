#include <cstdio>
int main() {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		int a0, a1, a2, a3;
		scanf("%d%d%d%d", &a0, &a1, &a2, &a3);
		int ans = a0/2 + a1/2 + a2/2 + a3/2 + (a0 % 2 & a1 % 2 & a2 % 2);
		printf("%d\n", ans);
	}
}
