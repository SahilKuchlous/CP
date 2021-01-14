#include <iostream>
using namespace std;
int main () {
	int n;
	cin >> n;
	int a[n];
	int freq[11];
	for (int i=0; i<=10; i++) {
		freq[i] = -1;
	}
	for (int i=0; i<n; i++) {
		cin >> a[i];
		freq[a[i]] = 0;
	}
	int o = 1;
	for (int i=0; i<n; i++) {
		freq[a[i]]++;
		int min_v = 1e7, max_v = 0;
		int min_c = 0, max_c = 0;
		int cnt = 0;
		for (int j=0; j<=10; j++) {
			if (freq[j] > 0) {
				cnt++;
				if (freq[j] < min_v) {
					min_v = freq[j];
					min_c = 1;
				} else if (freq[j] == min_v) {
					min_c++;
				}
				if (freq[j] > max_v) {
					max_v = freq[j];
					max_c = 1;
				} else if (freq[j] == max_v) {
					max_c++;
				}
			}
		}
		if (min_v == max_v-1 && max_c == 1) o = i;
		if (min_v == 1 && max_c >= cnt-1) o = i;
		if (cnt == 1) o = i;
	}
	cout << o+1 << endl;
}