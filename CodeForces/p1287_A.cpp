#include <iostream>
#include <string>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		s += 'A';
		int pi = -1;
		int md = 0;
		for (int i=0; i<s.length(); i++) {
			if (s.at(i) == 'A') {
				if (pi > -1) {
					md = max(md, i-pi-1);
				}
				pi = i;
			}
		}
		cout << md << endl;
	}
}