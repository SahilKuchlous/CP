#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
#define MAXN 500005
#define int long long
int n, m, o;
vector< pair<int, int> > rooms;
vector< pair<int, int> > grps;
multiset< pair<int, int> > rem;
int ptr = 0;
vector<int> scores;
int ans = 0;
signed main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> o;
	for (int i=0; i<n; i++) {
		rooms.push_back(make_pair(0, 0));
		cin >> rooms[i].first >> rooms[i].second;
		rem.insert(make_pair(rooms[i].second, rooms[i].first));
	}
	for (int i=0; i<m; i++) {
		grps.push_back(make_pair(0, 0));
		cin >> grps[i].first >> grps[i].second;
		grps[i].first = -grps[i].first;
	}
	sort(grps.begin(), grps.end());
	for (int i=0; i<m; i++) {
		if (rem.size() == 0) break;
		int val = -grps[i].first, cnt = grps[i].second;
		if (cnt > prev(rem.end())->first) continue;
		pair<int, int> best = *rem.lower_bound(make_pair(cnt, -1));
		scores.push_back(val-best.second);
		rem.erase(rem.find(best));
	}
	sort(scores.begin(), scores.end());
	while (o--) {
		if (scores.back() < 0) break;
		ans += scores.back();
		scores.pop_back();
	}
	cout << ans << endl;
}