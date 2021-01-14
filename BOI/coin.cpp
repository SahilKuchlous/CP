#include <iostream>
using namespace std;
int a[500100], b[500100];
int main () {
	int n, k;
	cin >> n >> k;
	for (int i=0; i<n; i++) {
		cin >> a[i] >> b[i];
	}
	a[n] = k;
	int cur = 0;
	int o = 0;
	for (int i=0; i<n; i++) {
		if (b[i]) continue;
		if (cur+a[i] < a[i+1]) {
			cur += a[i];
			o++;
		}
	}
	cout << o << endl << k - (cur ? cur:1) << endl;
}