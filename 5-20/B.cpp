#include <cstdio>
#include <iostream>
using namespace std;

char str[1000001];
int main() {
	int tc;
	cin >> tc;
	while(tc--) {
		int n;
		cin >> n;
		cin >> str;
		int fg[27] = {0};
		char ch[27];
		int ct = 0;
		for(int i = 0; i < n; i++)
			if(!fg[str[i] - 'a'])
				fg[str[i] - 'a'] = 1;
		for(int i = 0; i < 26; i++) {
			if(fg[i]) {
				ch[ct ++] = i + 'a';
				fg[i] = ct;
			}
		}
		
		for(int i = 0; i < n; i++) {
			cout << ch[ct - fg[str[i] - 'a']];
		}
		cout << endl;
	}
}
