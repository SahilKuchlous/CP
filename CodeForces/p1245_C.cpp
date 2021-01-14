#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define mod 1000000007
using namespace std;
long long f[100001];
int main () {
	string s;
	cin >> s;
	int c = 0;
	char x = '_';
	vector<int> v;
	int m = 0;
	bool p = true;
	for (auto i: s) {
		if (i == 'w' || i == 'm') {
			p = false;
			break;
		}
		if (i == x) {
			c++;
		} else {
			if (c > 1) {
				v.push_back(c);
			}
			c = 0;
			x = '_';
			if (i == 'u') {
				c++;
				x = 'u';
			} else if (i == 'n') {
				c++;
				x = 'n';
			}
		}
	}
	f[0] = 1;
	f[1] = 1;
	for (int i=2; i<100001; i++) {
		f[i] = (f[i-1] + f[i-2])%mod;
	}
	if (c > 1) {
		v.push_back(c);
	}
	long long o = 1;
	for (auto i: v) {
		o *= f[i];
		o %= mod;
	}
	if (p) {
		cout << o << endl;
	} else {
		cout << 0 << endl;
	}
}