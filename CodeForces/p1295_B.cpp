#include <iostream>
#include <string>
#include <map>
#include <cmath>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		string s;
		cin >> s;
		int bal[n];
		if (s.at(0) == '0') {
			bal[0] = 1;
		} else {
			bal[0] = -1;
		}
		int maxb, minb;
		maxb = bal[0];
		minb = bal[0];
		map<int, int> freq;
		freq[bal[0]]++;
		for (int i=1; i<n; i++) {
			if (s.at(i) == '0') {
				bal[i] = bal[i-1]+1;
			} else {
				bal[i] = bal[i-1]-1;
			}
			freq[bal[i]]++;
			maxb = max(maxb, bal[i]);
			minb = min(minb, bal[i]);
		}
		if (x == 0) {
			if (freq[0] > 0) {
				cout << -1 << endl;
			} else {
				cout << 1 << endl;
			}
		} else if (bal[n-1] == 0) {
			if (minb <= x && x <= maxb) {
				cout << -1 << endl;
			} else {
				cout << 0 << endl;
			}
		} else {
			long long o = 0;
			for (int i=minb; i<=maxb; i++) {
				if ((x<i && bal[n-1]<0 && (i-x)%abs(bal[n-1]) == 0) || (x>i && bal[n-1]>0 && (x-i)%abs(bal[n-1]) == 0)) {
					o += freq[i];
				}
			}
			cout << o << endl;
		}
	}
}