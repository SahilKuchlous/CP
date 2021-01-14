#include <iostream>
#include <algorithm>
using namespace std;
int main () {
	int n, k;
	cin >> n >> k;
	int a[n];
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	sort(a, a+n);
	int o = 0;
	for (int i=0; i<k; i++) {
		o += a[i];
	}
	cout << o << endl;
}