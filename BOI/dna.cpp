#include <iostream>
#include <set>
using namespace std;
int seq[200100];
pair<int, int> req[200100];
int pos[200100];
int cur[200100];
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, k, r;
	cin >> n >> k >> r;
	for (int i=0; i<n; i++) {
		cin >> seq[i];
	}
	for (int i=0; i<k; i++) {
		pos[i] = -1;
	}
	int ai, bi;
	multiset<int> pending;
	long long total = 0;
	for (int i=0; i<r; i++) {
		cin >> ai >> bi;
		pos[ai] = i;
		req[i] = make_pair(ai, bi);
		total += bi;
		if (total > n) break;
		for (int j=0; j<bi; j++) {
			pending.insert(ai);
		}
	}
	if (total > n) {
		cout << "impossible" << endl;
		return 0;
	}
	int lp = 0, rp = 0;
	cur[seq[0]]++;
	if (pending.find(seq[0]) != pending.end()) pending.erase(pending.find(seq[0]));
	int o = 1e8;
	while (true) {
		if (pending.size() > 0) {
			rp++;
			if (rp == n) break;
			cur[seq[rp]]++;
			if (pending.find(seq[rp]) != pending.end()) pending.erase(pending.find(seq[rp]));
			continue;
		}
		o = min(o, rp-lp+1);
		cur[seq[lp]]--;
		if (cur[seq[lp]] < req[pos[seq[lp]]].second) pending.insert(seq[lp]);
		lp++;
	}
	if (o == 1e8) {
		cout << "impossible" << endl;
	} else {
		cout << o << endl;
	}
}