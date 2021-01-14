#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main () {
	int n, q;
	cin >> n >> q;
	long long a[n];
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	vector<long long> cur;
	int l, r;
	long long k, rem, cost, min_c;
	bool done;
	for (int i=0; i<q; i++) {
		cur.clear();
		cin >> l >> r >> k;
		l--;
		r--;
		for (int j=l; j<=r; j++) {
			cur.push_back(a[j]);
		}
		sort(cur.begin(), cur.end());
		rem = k;
		done = false;
		for (int j=0; j<cur.size()-1; j++) {
			cost = (cur[j+1]-cur[j])*(j+1);
			if (cost <= rem) {
				rem -= cost;
			} else {
				min_c = cur[j]+rem/(j+1);
				done = true;
				break;
			}
		}
		if (done) {
			cout << *(cur.end()-1)-min_c << endl;
		} else {
			if (rem%cur.size() == 0) {
				cout << 0 << endl;
			} else {
				cout << 1 << endl;
			}
		}
	}
}