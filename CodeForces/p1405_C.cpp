#include <iostream>
#include <cmath>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		char s[n];
		for (int i=0; i<n; i++) {
			cin >> s[i];
		}
		char pos[k];
		for (int i=0; i<k; i++) {
			pos[i] = '?';
		}
		bool o = true;
		for (int i=0; i<n; i++) {
			if (s[i] == '?') continue;
			if (pos[i%k] != '?' && s[i] != pos[i%k]) {
				o = false;
				break;
			}
			pos[i%k] = s[i];
		}
		int cnt = 0, sum = 0;
		for (int i=0; i<k; i++) {
			if (pos[i] == '?') {
				cnt++;
			} else if (pos[i] == '0') {
				sum--;
			} else {
				sum++;
			}
		}
		if (abs(sum)-cnt > 0) o = false;
		if (o) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}