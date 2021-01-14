#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, a, b;
		cin >> n >> a >> b;
		string s = "";
		for (int i=0; i<a-b+1; i++) {
			s += 'a';
		}
		for (int i=0; i<b-1; i++) {
			s += 'a'+i+1;
		}
		string o = "";
		for (int i=0; i<n; i++) {
			o += s.at(i%a);
		}
		cout << o << endl;
	}
}