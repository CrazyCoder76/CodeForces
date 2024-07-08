#include <cstdio>

char str[501][501];
int main() {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		int n, m;
		scanf("%d%d", &n, &m);
		int fg1 = 0, fg2 = 0;
		for(int i = 0; i < n; i++) {
			scanf("\n%s", str[i]);
		}
		int min_wx = -1, min_wy = -1, max_wx = -1, max_wy = -1;
		int min_bx = -1, min_by = -1, max_bx = -1, max_by = -1;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++) {
				if(str[i][j] == 'W') {
					if(min_wx == -1 || i < min_wx) min_wx = i;
					if(min_wy == -1 || j < min_wy) min_wy = j;
					if(max_wx == -1 || i > max_wx) max_wx = i;
					if(max_wy == -1 || j > max_wy) max_wy = j;
				}
				else {
					if(min_bx == -1 || i < min_bx) min_bx = i;
					if(min_by == -1 || j < min_by) min_by = j;
					if(max_bx == -1 || i > max_bx) max_bx = i;
					if(max_by == -1 || j > max_by) max_by = j;
				}
			}
		
		if((min_wx == 0 && min_wy == 0 && max_wx == n-1 && max_wy == m-1) || (min_bx == 0 && min_by == 0 && max_bx == n-1 && max_by == m-1)) {
			puts("YES");
		}
		else {
			puts("NO");
		}
	}
}
