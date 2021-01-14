#include <iostream>
#include <vector>
#include <set>
#include <stack>
using namespace std;
int n, m;
set<int> adj[1000100];
int deg[1000100];
bool vis[1000100];
stack<int> st;
vector<int> v;
vector< pair<int, int> > cyc;
vector<int> state;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	int ai, bi;
	for (int i=0; i<m; i++) {
		cin >> ai >> bi;
		adj[ai].insert(bi);
		adj[bi].insert(ai);
		deg[ai]++; deg[bi]++;
	}
	for (int i=1; i<=n; i++) {
		if (deg[i]%2 == 1) {
			adj[i].insert(0);
			adj[0].insert(i);
		}
	}
	vector< pair<int, int> > o;
	for (int i=0; i<=n; i++) {
		if (vis[i]) continue;
		if (adj[i].size() == 0) continue;
		stack<int> st;
		st.push(i);
		while (st.size() > 0) {
			int cur = st.top();
			if (adj[cur].size() == 0) {
				v.push_back(cur);
				st.pop();
			} else {
				int nxt = *adj[cur].begin();
				adj[cur].erase(nxt);
				adj[nxt].erase(cur);
				st.push(nxt);
			}
		}
		int sz = v.size();
		for (int i=0; i<sz-1; i++) {
			cyc.push_back(make_pair(v[i], v[i+1]));
			state.push_back(((v[i] == 0 || v[i+1] == 0) ? 0:1));
		}
		for (int i=0; i<sz; i++) {
			if (i%2 == 0) {
				if (state[i] == 1) o.push_back(cyc[i]);
			} else {
				if (state[i] == 1 && (state[(i+sz+1)%sz] == 0 || state[(i+sz-1)%sz] == 0)) o.push_back(cyc[i]);
			}
		}
		v.clear();
		cyc.clear();
		state.clear();
	}
	cout << o.size() << endl;
	for (auto i: o) {
		cout << i.first << " " << i.second << endl;
	}
}