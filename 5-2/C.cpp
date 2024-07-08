#include <cstdio>
#include <cstring>

int a[501];
int b[501];
int main() {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		int n;
		scanf("%d", &n);
		n--;
		for(int i = 0; i < n; i++) scanf("%d", &a[i]);
		b[0] = 1000;
		for(int i = 0; i < n; i ++) {
			b[i+1] = b[i] + a[i];
		}
		for(int i = 0; i <= n; i++) {
			if(i) printf(" ");
			printf("%d", b[i]);
		}
		puts("");
	}
}
