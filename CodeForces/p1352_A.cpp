#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		string n;
		cin >> n;
		vector<string> o;
		string cur;
		for (int i=0; i<n.length(); i++) {
			if (n.at(i) != '0') {
				cur = n.at(i);
				for (int j=0; j<n.length()-i-1; j++) {
					cur += '0';
				}
				o.push_back(cur);
			}
		}
		cout << o.size() << endl;
		for (auto i: o) {
			cout << i << " ";
		}
		cout << endl;
	}
}