#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define MAXN 100005
int n;
long long s;
vector< pair<int, int> > adj[MAXN];
int wt[MAXN];
int cost[MAXN];
int sz[MAXN];
set< pair<long long, int> > ord1, ord2;
void reset () {
	for (int i=0; i<n; i++) {
		adj[i].clear();
		sz[i] = 0;
	}
	ord1.clear();
	ord2.clear();
}
void dfs (int x, int p) {
	bool leaf = true;
	for (auto i: adj[x]) {
		if (i.second == p) continue;
		leaf = false;
		dfs(i.first, i.second);
		if (p != -1) sz[p] += sz[i.second];
	}
	if (leaf) sz[p] = 1;
}
int main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> s;
		reset();
		int ai, bi, wi, ci;
		for (int i=0; i<n-1; i++) {
			cin >> ai >> bi >> wi >> ci;
			ai--; bi--;
			adj[ai].push_back(make_pair(bi, i));
			adj[bi].push_back(make_pair(ai, i));
			wt[i] = wi;
			cost[i] = ci;
		}
		dfs(0, -1);
		long long ttl = 0;
		for (int i=0; i<n-1; i++) {
			ttl += 1ll*sz[i]*wt[i];
			if (cost[i] == 1) {
				ord1.insert(make_pair(1ll*sz[i]*(wt[i]/2)-1ll*sz[i]*wt[i], i));
			} else {
				ord2.insert(make_pair(1ll*sz[i]*(wt[i]/2)-1ll*sz[i]*wt[i], i));
			}
		}
		int o = 0;
		while (ttl > s) {
			pair<long long, int> opt1_1, opt1_2, opt2;
			opt1_1 = opt1_2 = opt2 = make_pair(0, -1);
			if (ord2.size() > 0) opt2 = *ord2.begin();
			if (ord1.size() > 0) {
				opt1_1 = *ord1.begin();
				opt1_2 = make_pair(1ll*sz[opt1_1.second]*(wt[opt1_1.second]/2/2)-1ll*sz[opt1_1.second]*(wt[opt1_1.second]/2), opt1_1.second);
			}
			bool flag = false;
			if (ord1.size() > 1) {
				opt1_2 = min(opt1_2, *next(ord1.begin()));
				flag = true;
			}
			if (ttl+opt1_1.first <= s) {
				ttl += opt1_1.first;
				o++;
				break;
			}
			if (opt2.first <= opt1_1.first+opt1_2.first) {
				o += 2;
				ord2.erase(ord2.begin());
				ttl += opt2.first;
				wt[opt2.second] /= 2;
				ord2.insert(make_pair(1ll*sz[opt2.second]*(wt[opt2.second]/2)-1ll*sz[opt2.second]*wt[opt2.second], opt2.second));
				continue;
			} else {
				o++;
				ord1.erase(ord1.begin());
				ttl += opt1_1.first;
				wt[opt1_1.second] /= 2;
				ord1.insert(make_pair(1ll*sz[opt1_1.second]*(wt[opt1_1.second]/2)-1ll*sz[opt1_1.second]*wt[opt1_1.second], opt1_1.second));
			}
		}
		cout << o << endl;
	}
}