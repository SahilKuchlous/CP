#include <iostream>
#include <vector>
#include <map>
using namespace std;
#define MAXN 500005
#define MOD 1000000007
int n, m;
long long pow[MAXN][11];
vector<int> adj[MAXN];
long long o;
int cnt;
void calc () {
	for (int i=0; i<MAXN; i++) {
		pow[i][0] = 1;
		for (int j=1; j<=10; j++) {
			pow[i][j] = pow[i][j-1]*i % MOD;
		}
	}
}
long long pow2 (int x) {
	long long bin[25];
	bin[0] = 2;
	for (int i=1; i<25; i++) {
		bin[i] = bin[i-1]*bin[i-1] % MOD;
	}
	long long val = 1;
	for (int i=24; i>=0; i--) {
		if ((1<<i) <= x) {
			x -= (1<<i);
			val = val*bin[i] % MOD;
		}
	}
	return val;
}
int subtree[MAXN];
long long ttl[MAXN];
long long freq[MAXN];
bool dead[MAXN];
vector<long long> ind[MAXN];
void calc_subtree (int x, int p) {
	subtree[x] = 1;
	for (auto i: adj[x]) {
		if (i != p && !dead[i]) {
			calc_subtree(i, x);
			subtree[x] += subtree[i];
		}
	}
}
void dfs (int x, int p, int d, int id) {
	if (adj[x].size() == 1) ind[id][d]++;
	for (auto i: adj[x]) {
		if (i != p && !dead[i]) {
			dfs(i, x, d+1, id);
		}
	}
}
void solve (int x) {
	calc_subtree(x, -1);
	int root = x, p = -1, size = subtree[x];
	bool centroid;
	while (true) {
		centroid = true;
		for (auto i: adj[root]) {
			if (i != p && !dead[i] && subtree[i] > size/2) {
				centroid = false;
				p = root;
				root = i;
				break;
			}
		}
		if (centroid) break;
	}
	calc_subtree(root, root);
	for (int i=0; i<=size/2; i++) {
		freq[i] = 0;
	}
	if (adj[root].size() == 1) freq[0]++;
	for (auto i: adj[root]) {
		if (dead[i]) continue;
		ind[i].resize(subtree[i], 0);
		dfs(i, root, 1, i);
		for (int j=0; j<=size/2; j++) {
			ttl[j] += ind[i][j];
		}
	}
	
	dead[root] = true;
	for (auto i: adj[root]) {
		if (dead[i]) continue;
		solve(i);
	}
}
void init () {
	for (int i=0; i<=n; i++) {
		adj[i].clear();
		ttl[i] = 0;
		dead[i] = false;
	}
	o = cnt = 0;
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	calc();
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		init();
		int ai, bi;
		for (int i=0; i<n-1; i++) {
			cin >> ai >> bi;
			ai--; bi--;
			adj[ai].push_back(bi);
			adj[bi].push_back(ai);
		}
		bool line = true;
		for (int i=0; i<n; i++) {
			if (adj[i].size() > 2) line = false;
			if (adj[i].size() == 1) cnt++;
		}
		solve(0);
		for (int i=0; i<=n; i++) {
			o = (o + ttl[i]*pow[i][m] % MOD)%MOD;
		}
		cout << o << " ";
		if (m > 1 || !line) {
			cout << 1 << '\n';
		} else {
			cout << pow2(n-cnt) << '\n';
		}
	}
}