#include <iostream>
using namespace std;
int freq[100100];
int main () {
	int n;
	cin >> n;
	int a[n];
	long long sum = 0;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		freq[a[i]]++;
		sum += a[i];
	}
	int q;
	cin >> q;
	long long bi, ci;
	while (q--) {
		cin >> bi >> ci;
		sum -= bi*freq[bi];
		sum += ci*freq[bi];
		freq[ci] += freq[bi];
		freq[bi] = 0;
		cout << sum << endl;
	}
}