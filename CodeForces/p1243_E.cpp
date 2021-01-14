// Store the actual cycles.

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
using namespace std;

int k;
vector<long long> grps[16];
set<long long> opts; 
map< long long, int > id;
long long ttl[16];
long long avg = 0;
map< long long, vector< long long > > adj;

map< long long, bool > vis;
map< long long, bool > anc;
vector<long long> hist;
int ans = -1;
vector<long long> seq;
void dfs (int x) {
	if (anc[x]) {
		ans = 0;
		seq.push_back(x);
		for (int i=hist.size()-1; i>=0; i--) {
			if (ans & (1<<id[hist[i]])) {
				ans = -1;
				break;
			}
			ans += (1<<id[hist[i]]);
			seq.push_back(hist[i]);
			if (hist[i] == x) break;
		}
		return;
	}
	if (vis[x]) return;
	vis[x] = anc[x] = true;
	hist.push_back(x);
	for (auto i: adj[x]) {
		dfs(i);
	}
	anc[x] = false;
	hist.pop_back();
}

int bit[100000];
map< int, vector<long long> > cyc;

int main () {
	cin >> k;
	int a, b;
	for (int i=0; i<k; i++) {
		cin >> a;
		for (int j=0; j<a; j++) {
			cin >> b;
			grps[i].push_back(b);
			opts.insert(b);
			id[b] = i;
			ttl[i] += b;
			avg += b;
			vis[b] = anc[b] = false;
		}
	}
	if (avg%k != 0) {
		cout << "No" << endl;
		return 0;
	}
	avg /= k;
	for (int i=0; i<k; i++) {
		for (auto j: grps[i]) {
			if (opts.find(j+avg-ttl[i]) != opts.end()) adj[j].push_back(j+avg-ttl[i]);
		}
	}
	for (int i=0; i<(1<<k); i++) {
		bit[i] = -1;
	}
	for (int i=0; i<k; i++) {
		for (auto j: grps[i]) {
			if (vis[j]) continue;
			ans = -1;
			seq.clear();
			dfs(j);
			if (ans != -1) {
				bit[ans] = ans;
				cyc[ans] = seq;
			}
		}
	}
	for (int i=0; i<(1<<k); i++) {
		if (bit[i] > -1) continue;
		for (int j=i; j>0; j = (j-1)&i) {
			if (bit[j] > 0 && bit[i^j] > 0) bit[i] = j;
		}
	}
	if (bit[(1<<k)-1] == -1) {
		cout << "No" << endl;
		return 0;
	}
	pair<long long, int> o[k];
	stack<int> cur;
	cur.push((1<<k)-1);
	while (cur.size() > 0) {
		int mask = cur.top();
		cur.pop();
		if (bit[mask] == mask) {
			for (int i=0; i<cyc[mask].size()-1; i++) {
				o[id[cyc[mask][i]]] = make_pair(cyc[mask][i], id[cyc[mask][i+1]]);
			}
		} else {
			cur.push(bit[mask]);
			cur.push(mask^bit[mask]);
		}
	}
	cout << "Yes" << endl;
	for (int i=0; i<k; i++) {
		cout << o[i].first << " " << o[i].second+1 << endl;
	}
}