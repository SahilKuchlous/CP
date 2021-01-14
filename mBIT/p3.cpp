#include <iostream>
#include <cmath>
using namespace std;
#define MAXN 100005
int n;
int a[MAXN], b[MAXN];
int pos_a[MAXN], pos_b[MAXN];
int dif[MAXN];
int cnt[MAXN];
int inc = 0, red = 0;
long long ttl = 0;
long long o = 1e16;
int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		a[i]--;
		pos_a[a[i]] = i;
	}
	for (int i=0; i<n; i++) {
		cin >> b[i];
		b[i]--;
		pos_b[b[i]] = i;
	}
	for (int i=0; i<n; i++) {
		dif[i] = pos_a[i]-pos_b[i];
		ttl += abs(dif[i]);
		if (dif[i] >= 0) {
			red++;
			cnt[dif[i]]++;
		} else {
			inc++;
			cnt[n+dif[i]]++;
		}
	}
	o = ttl;
	for (int i=0; i<n; i++) {
		red -= cnt[i];
		inc += cnt[i];
		inc--;
		red++;
		ttl += inc;
		ttl -= red;
		ttl -= n-pos_a[b[n-i-1]]-1;
		ttl += pos_a[b[n-i-1]]+1;
		o = min(o, ttl);
	}
	cout << o << endl;
}