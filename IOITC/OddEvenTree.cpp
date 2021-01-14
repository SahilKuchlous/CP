#include <iostream>
#include <vector>
#include <unordered_set>
#include <map>

using namespace std;

vector< vector<int> > t;
map< pair<int, int>, vector<int> > memo; 

vector<int> dfs (int nd, int v, bool s) {
	vector<int> r;
	vector<int> p;
	p.push_back(1);
	p.push_back(0);
	pair<int, int> k;
	k.first = v;
	k.second = nd;
	if (memo.find(k) != memo.end()) {
		return memo[k];
	}
	for (auto x: t[nd]) {
		if (x != v) {
			r = dfs(x, nd, !s);
			p[0] += r[1];
			p[1] += r[0];
		}
	}
	memo[k] = p;
	return p;
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		vector<int> x;
		t.push_back(x);
	}
	for (int i=0; i<n-1; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		t[u].push_back(v);
		t[v].push_back(u);
	}
	for (int i=0; i<n; i++) {
		vector<int> d;
		vector< vector<int> > s;
		vector<int> o;
		o.push_back(1);
		o.push_back(0);
		int s0 = 0;
		int s1 = 0;
		for (auto j: t[i]) {
			d = dfs(j, i, true);
			o[0] += d[1];
			o[1] += d[0];
			s0 += d[0];
			s1 += d[1];
			s.push_back(d);
		}
		for (int j=0; j<t[i].size()-1; j++) {
			s0 -= s[j][0];
			s1 -= s[j][1];
			o[0] += s[j][0]	* s0;
			o[0] += s[j][1]	* s1;
			o[1] += s[j][1] * s0;
			o[1] += s[j][0] * s1;
		}
		cout << o[1] << " " << o[0] << endl;
	}
}