#include <iostream>
using namespace std;
int n, k;
int a[100005];
int ttl[100005];
int bv = 1e9, bi;
int main () {
	cin >> n >> k;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		ttl[i%k] += a[i];
	}
	for (int i=0; i<k; i++) {
		if (ttl[i] < bv) {
			bv = ttl[i];
			bi = i;
		}
	}
	cout << bi+1 << endl;
}