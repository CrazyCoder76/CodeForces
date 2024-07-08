#include <cstdio>

int a[200001];
int main() {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	    int min_val = 1e9;
	    for (int i = 0; i < n; i++) {
	        if (a[i] < min_val) {
	            min_val = a[i];
	        }
	    }
	    
        int count_mins = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == min_val) {
                count_mins++;
            }
        }

        if (min_val == 1 && count_mins < n) {
            printf("Bob\n");
        } else {
            printf("Alice\n");
        }
	}
}
