#include <iostream>
#include <string>
#include <map>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int d;
		cin >> d;
		string m;
		int l, h;
		map< string, pair<int, int> > data;
		for (int i=0; i<d; i++) {
			cin >> m >> l >> h;
			data[m] = make_pair(l, h);
		} 
		int q, p;
		cin >> q;
		string o;
		for (int i=0; i<q; i++) {
			o = "";
			cin >> p;
			for (auto j: data) {
				if (j.second.first <= p && p <= j.second.second) {
					if (o == "") {
						o = j.first;
					} else {
						o = "UNDETERMINED";
					}
				}
			}
			if (o == "") {
				cout << "UNDETERMINED" << endl;
			} else {
				cout << o << endl;
			}
		}
		if (t != 0) {
			cout << endl;
		}
	}
}