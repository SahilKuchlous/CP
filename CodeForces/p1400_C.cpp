#include <iostream>
using namespace std;
#define MAXN 100005
string s;
int k, n;
int o[MAXN];
int main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> s;
		cin >> k;
		n = s.length();
		for (int i=0; i<n; i++) {
			o[i] = 1;
		}
		for (int i=0; i<n; i++) {
			if (s[i] == '0') {
				if (i-k >= 0) o[i-k] = 0;
				if (i+k < n) o[i+k] = 0;
			}
		}
		bool pos = true;
		for (int i=0; i<n; i++) {
			if (s[i] == '0') continue;
			if ((i-k >= 0 && o[i-k] == 1) || (i+k < n && o[i+k] == 1)) continue;
			pos = false;
			break;
		}
		if (!pos) {
			cout << -1 << endl;
			continue;
		}
		for (int i=0; i<n; i++) {
			cout << o[i];
		}
		cout << endl;
	}
}