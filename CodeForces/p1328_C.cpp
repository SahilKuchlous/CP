#include <iostream>
#include <string>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string x;
		cin >> x;
		string a = "", b = "";
		int end = n-1;
		for (int i=0; i<n; i++) {
			if (x.at(i) == '0') {
				a += '0';
				b += '0';
			} else if (x.at(i) == '2') {
				a += '1';
				b += '1';
			} else {
				a += '1';
				b += '0';
				end = i;
				break;
			}
		}
		for (int i=end+1; i<n; i++) {
			a += '0';
		}
		if (end < n-1) b += x.substr(end+1, n-end-1);
		cout << a << endl << b << endl;
	}
}