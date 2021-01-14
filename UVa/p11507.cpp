#include <iostream>
#include <string>
using namespace std;
int main () {
	while (true) {
		int l;
		cin >> l;
		if (l == 0) {
			break;
		}
		string y[] = {"+x", "+y", "-x", "-y"};
		string z[] = {"+x", "+z", "-x", "-z"};
		int d = 100000;
		int yz = 0;
		string ins;
		for (int i=0; i<l-1; i++) {
			cin >> ins;
			if (ins == "+y") {
				if (yz == 0) {
					yz = 1;
				}
				if (yz == 1) {
					d++;
					if (d%4 == 0 || d%4 == 2) {
						yz = 0;
					}
				}
			} else if (ins == "-y") {
				if (yz == 0) {
					yz = 1;
				}
				if (yz == 1) {
					d--;
					if (d%4 == 0 || d%4 == 2) {
						yz = 0;
					}
				}
			} else if (ins == "+z") {
				if (yz == 0) {
					yz = 2;
				}
				if (yz == 2) {
					d++;
					if (d%4 == 0 || d%4 == 2) {
						yz = 0;
					}
				}
			} else if (ins == "-z") {
				if (yz == 0) {
					yz = 2;
				}
				if (yz == 2) {
					d--;
					if (d%4 == 0 || d%4 == 2) {
						yz = 0;
					}
				}
			}
		}
		if (yz == 0) {
			cout << y[(d%4)] << endl;
		} else if (yz == 1) {
			cout << y[(d%4)] << endl;
		} else if (yz == 2) {
			cout << z[(d%4)] << endl;
		}
	}
}