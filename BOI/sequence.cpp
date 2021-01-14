#include <iostream>
#include <algorithm>
using namespace std;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int a[n];
	pair<int, int> seq[n];
	int l[n], r[n];
	for (int i=0; i<n; i++) {
		cin >> a[i];
		seq[i] = make_pair(a[i], i);
		l[i] = i-1;
		r[i] = i+1;
	}
	sort(seq, seq+n);
	long long o = 0;
	for (int i=0; i<n-1; i++) {
		int cur = seq[i].second;
		if (l[cur] < 0) {
			o += a[r[cur]];
			l[r[cur]] = l[cur];
		} else if (r[cur] >= n) {
			o += a[l[cur]];
			r[l[cur]] = r[cur];
		} else {
			o += min(a[l[cur]], a[r[cur]]);
			l[r[cur]] = l[cur];
			r[l[cur]] = r[cur];
		}
	}
	cout << o << '\n';
}