#include <iostream>
#include <vector>
using namespace std;
#define MAXN 200005
#define MOD 998244353
int n;
vector<int> adj[MAXN];
long long fact[MAXN];
void compute () {
	fact[1] = 1;
	for (int i=2; i<MAXN; i++) {
		fact[i] = (fact[i-1]*i)%MOD;
	}
}
vector< pair<long long, int> > parts;
pair<long long, int> dfs (int x, int p) {
	pair<long long, int> cur = {1, 1};
	int cnt = 1;
	for (auto i: adj[x]) {
		if (i == p) continue;
		pair<long long, int> nxt = dfs(i, x);
		cur.first *= nxt.first;
		cur.first %= MOD;
		cur.second += nxt.second;
		cnt++;
	}
	cur.first *= fact[cnt];
	cur.first %= MOD;
	return cur;
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	int ai, bi;
	for (int i=0; i<n-1; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		adj[ai].push_back(bi);
		adj[bi].push_back(ai);
	}
	compute();
	for (auto i: adj[0]) {
		parts.push_back(dfs(i, 0));
	}
	parts.push_back(make_pair(1, 1));
	long long ord = 1;
	for (auto i: parts) {
		ord *= i.first;
		ord %= MOD;
	}
	long long ttl = 0;
	for (auto i: parts) {
		ttl += (i.second*ord%MOD)*fact[adj[0].size()]%MOD;
		ttl %= MOD;
	}
	cout << ttl << endl;
}