#include <iostream>
using namespace std;
#define MAXN 105
#define MAXK 105
int tcnt[MAXK];
int fcnt[MAXK];
int main () {
	int n, k;
	cin >> n >> k;
	for (int i=0; i<n; i++) {
		for (int j=0; j<k; j++) {
			char ans;
			cin >> ans;
			if (ans == 'T') {
				tcnt[j]++;
			} else if (ans == 'F') {
				fcnt[j]++;
			}
		}
	}
	string o = "";
	bool pos = true;
	for (int i=0; i<k; i++) {
		if (fcnt[i] <= 1) {
			o += "F";
		} else if (tcnt[i] <= 1) {
			o += "T";
		} else {
			pos = false;
		}
	}
	if (pos) {
		cout << o << endl;
	} else {
		cout << -1 << endl;
	}
}