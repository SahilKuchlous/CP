#include <iostream>
using namespace std;
int main () {
	int a[4];
	cin >> a[0] >> a[1] >> a[2] >> a[3];
	int cnt = 0;
	for (int i=0; i<4; i++) {
		bool org = true;
		for (int j=0; j<i; j++) {
			if (a[j] == a[i]) org = false;
		}
		if (org) cnt++;
	}
	cout << 4-cnt << endl;
}