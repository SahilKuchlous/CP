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
		bool lo[n], hi[n];
		for (int i=0; i<n; i++) {
			lo[i] = hi[i] = false;
		}
		for (int i=1; i<n-1; i++) {
			if (a[i] > a[i-1] && a[i] > a[i+1]) hi[i] = true;
			if (a[i] < a[i-1] && a[i] < a[i+1]) lo[i] = true;
		}
		int cnt = 0, best = 0;
		for (int i=1; i<n-1; i++) {
			if (lo[i] || hi[i]) cnt++;
			best = max(best, (lo[i]|hi[i]));
			if (lo[i-1] || hi[i-1] || lo[i+1] || hi[i+1]) best = max(best, 1+(lo[i]|hi[i]));
			if ((lo[i-1] && lo[i+1]) || (hi[i-1] && hi[i+1])) best = 2+(lo[i]|hi[i]);
		}
		cout << cnt-best << endl;
	}
}