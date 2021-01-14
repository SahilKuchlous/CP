#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct person {
	int id;
	int bag;
	int wt;
	bool operator< (const person &p1) const {
		return wt > p1.wt;
	}
};
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	person ppl[n];
	person ord[n];
	int bags[n];
	for (int i=0; i<n; i++) {
		ppl[i].id = ord[i].id = i;
		cin >> ppl[i].wt;
		ord[i].wt = ppl[i].wt;
	}
	for (int i=0; i<n; i++) {
		cin >> bags[i];
	}
	for (int i=0; i<n; i++) {
		cin >> ppl[i].bag;
		ppl[i].bag--;
		ord[i].bag = ppl[i].bag;
	}
	sort(ord, ord+n);
	bool done[n];
	for (int i=0; i<n; i++) {
		done[i] = false;
	}
	vector< pair<int, int> > o;
	bool pos = true;
	for (int i=0; i<n; i++) {
		if (done[ord[i].id]) continue;
		int cur = ord[i].bag;
		while (cur != ord[i].id) {
			if (bags[cur] >= ord[i].wt || bags[ppl[cur].bag] >= ppl[cur].wt) {
				pos = false;
				break;
			}
			o.push_back(make_pair(ord[i].id, cur));
			done[cur] = true;
			cur = ppl[cur].bag;
		}
		done[ord[i].id] = true;
		if (!pos) break;
	}
	if (pos) {
		cout << o.size() << endl;
		for (auto i: o) {
			cout << i.first+1 << " " << i.second+1 << endl;
		}
	} else {
		cout << -1 << endl;
	}
}