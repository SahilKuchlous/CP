#include <iostream>
#include <string>
using namespace std;
int main () {
	int t, b;
	cin >> t >> b;
	for (int z=0; z<t; z++) {
		string o = "";
		char inp;
		for (int i=0; i<b; i++) {
			cout << i+1 << endl;
			cin >> inp;
			o += inp;
		}
		cout << o << endl;
		cin >> inp;
	}
}