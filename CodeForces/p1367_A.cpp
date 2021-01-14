#include <iostream>
#include <string>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		string a;
		cin >> a;
		string o = "";
		o += a.at(0);
		for (int i=1; i<a.length()-1; i+=2) {
			o += a.at(i);
		}
		o += a.at(a.length()-1);
		cout << o << endl;
	}
}