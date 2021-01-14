#include <iostream>
using namespace std;
#define MAXN 100005
int n;
long long a[MAXN];
long long p = 1, o = 1;
int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		if (a[i] == 0) {
			cout << 0 << endl;
			return 0;
		}
	}
	for (int i=0; i<n; i++) {
		if (a[i] > (long long)(1e18/o)) {
			cout << -1 << endl;
			return 0;
		}
		o *= a[i];
		p = o;
	}
	if (o > (long long)1e18) o = -1;
	cout << o << endl;
}