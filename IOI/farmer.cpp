#include <iostream>
#include <algorithm>
using namespace std;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, a, b;
	cin >> n >> a >> b;
	int cycles[a];
	for (int i=0; i<a; i++) {
		cin >> cycles[i];
	}
	int lines[b];
	for (int i=0; i<b; i++) {
		cin >> lines[i];
	}
	bool dp[n+1];
	for (int i=0; i<=n; i++) {
		dp[i] = false;
	}
	dp[0] = true;
	for (int i=0; i<a; i++) {
		for (int j=n-cycles[i]; j>=0; j--) {
			if (dp[j]) dp[j+cycles[i]] = true;
		}
	}
	if (dp[n]) {
		cout << n << endl;
		return 0;
	}
	int total = 0;
	for (int i=0; i<a; i++) {
		total += cycles[i];
	}
	if (total > n) {
		cout << n-1 << endl;
		return 0;
	}
	int rem = n-total;
	sort(lines, lines+b, greater<int>());
	for (int i=0; i<b; i++) {
		rem -= lines[i];
		n--;
		if (rem <= 0) break;
	}
	cout << n << endl;
	return 0;
}