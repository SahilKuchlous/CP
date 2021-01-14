#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n];
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}
		int apos = 0, bpos = n-1;
		int cnt = 0;
		int atot = 0, btot = 0;
		int aprev = 0, bprev = 0;
		bool turn = true;
		while (apos <= bpos) {
			if (turn) {
				if (aprev <= bprev) {
					aprev += a[apos];
					atot += a[apos];
					apos++;
				} else {
					bprev = 0;
					turn = false;
					cnt++;
				}
			} else {
				if (bprev <= aprev) {
					bprev += a[bpos];
					btot += a[bpos];
					bpos--;
				} else {
					aprev = 0;
					turn = true;
					cnt++;
				}
			}
		}
		cout << cnt+1 << " " << atot << " " << btot << endl;
	}
}