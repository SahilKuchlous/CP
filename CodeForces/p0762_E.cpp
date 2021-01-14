#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
struct station {
	int x, r, f;
	bool operator < (const station s) const {
		return r < s.r;
	}
};
int n, k;
station stations[100100];
map< int, vector<int> > freq;
map< int, vector<int> > bits;
long long o;
void update (int f, int p) {
	p++;
	while (p <= freq[f].size()) {
		bits[f][p]++;
		p += p&-p;
	}
}
long long query (int f, int p) {
	long long o = 0;
	while (p > 0) {
		o += bits[f][p];
		p -= p&-p;
	}
	return o;
}
int main () {
	cin >> n >> k;
	for (int i=0; i<n; i++) {
		cin >> stations[i].x >> stations[i].r >> stations[i].f;
	}
	sort(stations, stations+n);
	for (int i=0; i<n; i++) {
		freq[stations[i].f].push_back(stations[i].x);
	}
	for (auto &i: freq) {
		sort(freq[i.first].begin(), freq[i.first].end());
		bits[i.first].resize(freq[i.first].size()+1, 0);
	}
	for (int i=n-1; i>=0; i--) {
		for (int j=stations[i].f-k; j<=stations[i].f+k; j++) {
			if (freq[j].size() == 0) continue;
			int l = lower_bound(freq[j].begin(), freq[j].end(), stations[i].x-stations[i].r) - freq[j].begin();
			int u = upper_bound(freq[j].begin(), freq[j].end(), stations[i].x+stations[i].r) - freq[j].begin();
			int c = query(j, u) - query(j, l);
			if (c > 0) o += c;
		}
		int p = lower_bound(freq[stations[i].f].begin(), freq[stations[i].f].end(), stations[i].x) - freq[stations[i].f].begin();
		update(stations[i].f, p);
	}
	cout << o << endl;
}