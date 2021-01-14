#include <iostream>
#include <string>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		k--;
		int pos1 = 1;
		int kc = k;
		while (true) {
			if (kc < pos1) break;
			kc -= pos1;
			pos1++;
		}
		int pos2 = kc;
		string o = "";
		for (int i=n-1; i>=0; i--) {
			if (i == pos1 || i == pos2) {
				o += "b";
			} else {
				o += "a";
			}
		}
		cout << o << endl;
	}
}