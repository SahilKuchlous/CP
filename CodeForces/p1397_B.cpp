#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 100005
int n;
int a[MAXN];
long long o;
int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	sort(a, a+n);
	o = 0;
	for (int i=0; i<n; i++) {
		o += a[i]-1;
	}
	if (n >= 100) {
		cout << o << endl;
		return 0;
	}
}