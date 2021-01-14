#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;
int main () {
	int b, n;
	cin >> b >> n;
	vector<int> opts;
	for (int i=pow(b, n-1); i<pow(b, n); i++) {
		int temp = i;
		bool pos = true;
		while (temp > 0) {
			int dig = temp%b;
			temp /= b;
			if (dig == 0 || i%dig != 0) {
				pos = false;
				break;
			}
		}
		if (pos) opts.push_back(i);
	}
	int t;
	cin >> t;
	while (t--) {
		char val[b];
		for (int i=0; i<b; i++) {
			cin >> val[i];
		}
		int o = 0;
		for (auto i: opts) {
			int temp = i;
			bool pos = true;
			while (temp > 0) {
				int dig = temp%b;
				temp /= b;
				if (val[dig] == '0') {
					pos = false;
					break;
				}
			}
			if (pos) o++;
		}
		cout << o << endl;
	}
}