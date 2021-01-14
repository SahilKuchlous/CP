#include <iostream>
#include <algorithm>
using namespace std;
int main () {
	int n;
	cin >> n;
	int a[n];
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	sort(a, a+n, greater<int>());
	long long ans = a[0];
	int cnt = n-2;
	for (int i=1; i<n; i++) {
		ans += a[i]*min(2, cnt);
		cnt -= 2;
		if (cnt <= 0) break;
	}
	cout << ans << endl;
}