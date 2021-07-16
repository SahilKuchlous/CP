#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	long long pos[n];
	for (int i=0; i<n; i++) {
		cin >> pos[i];
	}
	long long wind[q];
	for (int i=0; i<q; i++) {
		cin >> wind[i];
	}
	long long cur = 0, f = 0, b = 0;
	vector< pair<long long, long long> > vf, vb;
	vf.push_back(make_pair(0, 0));
	vb.push_back(make_pair(0, 0));
	for (int i=0; i<q; i++) {
		cur += wind[i];
		if (cur > f) {
			f = cur;
			vf.push_back(make_pair(f+b, b));
		}
		if (-cur > b) {
			b = -cur;
			vb.push_back(make_pair(f+b, f));
		}
	}
	vf.push_back(make_pair(1e18, 1e18));
	vb.push_back(make_pair(1e18, 1e18));
	long long o[n];
	for (int i=0; i<n; i++) {
		o[i] = 0;
		if (i == 0 || pos[i]-pos[i-1] >= f+b) {
			o[i] += b;
		} else {
			pair<long long, long long> val1 = *lower_bound(vb.begin(), vb.end(), make_pair(pos[i]-pos[i-1], -1ll));
			pair<long long, long long> val2 = *lower_bound(vf.begin(), vf.end(), make_pair(pos[i]-pos[i-1], -1ll));
			if (val1.first < val2.first) {
				o[i] += pos[i]-pos[i-1]-val1.second;
			} else {
				o[i] += val2.second;
			}
		}
		if (i == n-1 || pos[i+1]-pos[i] >= f+b) {
			o[i] += f;
		} else {
			pair<long long, long long> val1 = *lower_bound(vf.begin(), vf.end(), make_pair(pos[i+1]-pos[i], -1ll));
			pair<long long, long long> val2 = *lower_bound(vb.begin(), vb.end(), make_pair(pos[i+1]-pos[i], -1ll));
			if (val1.first < val2.first) {
				o[i] += pos[i+1]-pos[i]-val1.second;
			} else {
				o[i] += val2.second;
			}
		}
		cout << o[i] << '\n';
	}
}