#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
#define MAXN 200005
int n;
pair<int, int> bids[MAXN];
vector<int> ind[MAXN];
vector< pair<int, int> > ord;
int q;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> bids[i].first >> bids[i].second;
		bids[i].first--;
		ind[bids[i].first].push_back(bids[i].second);
	}
	for (int i=0; i<n; i++) {
		if (ind[i].size() > 0) {
			ord.push_back(make_pair(ind[i].back(), i));
		}
	}
	sort(ord.begin(), ord.end(), greater< pair<int, int> >());
	cin >> q;
	while (q--) {
		int cnt;
		cin >> cnt;
		set<int> ban;
		int inp;
		for (int i=0; i<cnt; i++) {
			cin >> inp;
			inp--;
			ban.insert(inp);
		}
		int p = -1, l = -1;
		for (auto i: ord) {
			if (ban.find(i.second) != ban.end()) continue;
			if (p == -1) {
				p = i.second;
			} else {
				l = i.first;
				break;
			}
		}
		if (p == -1) {
			cout << "0 0" << '\n';
			continue;
		}
		int final = *lower_bound(ind[p].begin(), ind[p].end(), l);
		cout << p+1 << " " << final << '\n';
	}
}