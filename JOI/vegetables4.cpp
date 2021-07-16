#include <iostream>
using namespace std;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int a[n];
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	long long pre[n];
	pre[0] = 0;
	for (int i=1; i<n; i++) {
		pre[i] = pre[i-1]+max(0, a[i-1]-a[i]+1);
	}
	long long suf[n];
	suf[n-1] = 0;
	for (int i=n-2; i>=0; i--) {
		suf[i] = suf[i+1]+max(0, a[i+1]-a[i]+1);
	}
	long long o = 1e16;
	for (int i=0; i<n; i++) {
		o = min(o, max(pre[i], suf[i]));
	}
	cout << o << endl;
}