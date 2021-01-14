#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		int c1 = 0, c2 = 0;
		for (int i=1; i<n; i++) {
			if (s[i] == '1' && s[i-1] == '1') c1++;
			if (s[i] == '0' && s[i-1] == '0') c2++;
		}
		cout << max(c1, c2) << endl;
	}
}