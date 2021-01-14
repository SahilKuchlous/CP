#include <iostream>
#include <algorithm>
using namespace std;
int main () {
	int n;
	cin >> n;
	int a[n+1];
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	a[n] = 0;
	sort(a, a+n+1);
	for (int i=1; i<=n; i++) {
		if (a[i]-a[i-1] > 1) {
			cout << a[i-1]+1 << endl;
			return 0;
		}
	}
	cout << a[n]+1 << endl;
}