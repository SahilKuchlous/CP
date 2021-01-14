#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int d, m, n;
pair<int, int> pts[200100];
set<int> done;
long long o = 0;
int main () {
	cin >> d >> m >> n;
	for (int i=0; i<n; i++) {
		cin >> pts[i].second >> pts[i].first;
	}
	sort(pts, pts+n);
	done.insert(0);
	done.insert(d);
	for (int i=0; i<n; i++) {
		int prv = *prev(done.lower_bound(pts[i].second));
		int nxt = *done.lower_bound(pts[i].second);
		int rem = max(0, m-(pts[i].second-prv));
		if (nxt-pts[i].second <= m) {
			o += 1ll*max(0, nxt-pts[i].second-rem)*pts[i].first;
		} else {
			o += 1ll*(m-rem)*pts[i].first;
		}
		done.insert(pts[i].second);
	}
	int prev = 0;
	for (auto i: done) {
		if (i-prev > m) {
			o = -1;
			break;
		}
		prev = i;
	}
	cout << o << endl;
}