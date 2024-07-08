#include <cstdio>
#include <cstring>

char str1[200001];
char str2[200001];
int main() {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		int n, m;
		scanf("%d%d", &n, &m);
		scanf("\n%s\n%s", str1, str2);
		int len1 = strlen(str1), len2 = strlen(str2);
		int j = 0;
		for(int i = 0; i < len2 && j < len1; i++) {
			if(str2[i] == str1[j]) j++;
		}
		printf("%d\n" , j);
	}
}
