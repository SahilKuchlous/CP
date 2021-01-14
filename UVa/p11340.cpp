#include <iostream>
#include <map>
#include <string>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int k;
		cin >> k;
		map<char, int> d;
		char c;
		int v;
		for (int i=0; i<k; i++) {
			cin >> c >> v;
			d[c] = v;
		}
		int m;
		cin >> m;
		cin >> ws;
		long long s = 0;
		string in;
		for (int i=0; i<m; i++) {
			getline(cin, in);
			for (int j=0; j<in.size(); j++) {
				if (d.find(in[j]) != d.end()) {
					s += d[in[j]];
				}
			}
		}
		if (s%100 < 10) {
			cout << s/100 << ".0" << s%100 << "$" << endl;
		} else {
			cout << s/100 << "." << s%100 << "$" << endl;
		}
	}
}