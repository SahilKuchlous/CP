#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAXN 100005
int n, k;
vector< pair<int, int> > adj[MAXN];
int deg[MAXN];
int sub[MAXN];
queue<int> ord;
bool check (int x) {
	for (int i=0; i<n; i++) {
		deg[i] = adj[i].size();
		if (deg[i] == 1) ord.push(i);
		sub[i] = 0;
	}
	while (ord.size() > 0) {
		int cur = ord.front();
		ord.pop();
		int p = -1, dist = -1;
		for (auto i: adj[cur]) {
			if (deg[i.first] == 0) continue;
			p = i.first;
			dist = i.second;
			break;
		}
		if (p == -1) continue;
		if (sub[cur]+dist > x) continue;
		sub[p] = max(sub[p], sub[cur]+dist);
		deg[cur]--; deg[p]--;
		if (deg[p] == 1) ord.push(p);
	}
	int cnt1 = 0, cnt2 = 0;
	bool pos = true;
	for (int i=0; i<n; i++) {
		if (deg[i] > 2) {
			pos = false;
			break;
		}
		if (deg[i] == 2) cnt2++;
		if (deg[i] == 1) cnt1++;
	}
	if (pos && cnt1 <= 2 && cnt1+cnt2 <= k) return true;
	return false;
}
int main () {
	cin >> n >> k;
	int ai, bi, wi;
	for (int i=0; i<n-1; i++) {
		cin >> ai >> bi >> wi;
		ai--; bi--;
		adj[ai].push_back(make_pair(bi, wi));
		adj[bi].push_back(make_pair(ai, wi));
	}
	int l = 0, r = 1e9, mid, o;
	while (l <= r) {
		mid = (l+r)/2;
		if (check(mid)) {
			o = mid; r = mid-1;
		} else {
			l = mid+1;
		}
	}
	cout << o << endl;
}