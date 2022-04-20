#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	for (int tn=1; tn<=t; tn++) {
		cout << "Case #" << tn << ":\n";
		int r, c;
		cin >> r >> c;
		cout << "..";
		for (int i=0; i<2*c-1; i++) {
			if (i%2 == 0) {
				cout << "+";
			} else {
				cout << "-";
			}
		}
		cout << endl;
		cout << "..";
		for (int i=0; i<2*c-1; i++) {
			if (i%2 == 0) {
				cout << "|";
			} else {
				cout << ".";
			}
		}
		cout << endl;
		for (int i=0; i<2*r-1; i++) {
			for (int j=0; j<2*c+1; j++) {
				if (i%2 == 0 && j%2 == 0) {
					cout << "+";
				} else if (i%2 == 0 && j%2 == 1) {
					cout << "-";
				} else if (i%2 == 1 && j%2 == 0) {
					cout << "|";
				} else {
					cout << ".";
				}
			}
			cout << endl;
		}
	}
}