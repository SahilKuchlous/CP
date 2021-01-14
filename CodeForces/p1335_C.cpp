#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n];
		int freq[n];
		for (int i=0; i<n; i++) {
			freq[i] = 0;
		}
		int max_freq = 0;
		for (int i=0; i<n; i++) {
			cin >> a[i];
			a[i]--;
			freq[a[i]]++;
			max_freq = max(max_freq, freq[a[i]]);
		}
		int cnt = 0;
		for (int i=0; i<n; i++) {
			if (freq[i] > 0) cnt++;
		}
		if (cnt == max_freq) {
			cout << cnt-1 << endl;
		} else {
			cout << min(cnt, max_freq) << endl;
		}
	}
}