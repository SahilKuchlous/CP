#include <iostream>
#include <set>
using namespace std;
#define MAXN 100005
int n, m;
set<int> adj[MAXN];
bool pos = true;
set<int> g1, g2, g3;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	int ai, bi;
	for (int i=0; i<m; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		adj[ai].insert(bi);
		adj[bi].insert(ai);
	}
	g1.insert(0);
	int nxt = 0;
	for (int i=0; i<n; i++) {
		if (adj[0].find(i) == adj[0].end()) {
			g1.insert(i);
		} else {
			nxt = i;
		}
	}
	for (int i=0; i<n; i++) {
		if (adj[nxt].find(i) == adj[nxt].end()) {
			if (g1.find(i) != g1.end()) {
				pos = false;
			}
			g2.insert(i);
		}
	}
	for (int i=0; i<n; i++) {
		if (g1.find(i) == g1.end() && g2.find(i) == g2.end()) g3.insert(i);
	}
	int rep = *g1.begin();
	for (auto i: g1) {
		if (adj[i].size() != adj[rep].size()) pos = false;
		for (auto j: adj[i]) {
			if (adj[rep].find(j) == adj[rep].end()) pos = false;
		}
	}
	rep = *g2.begin();
	for (auto i: g2) {
		if (adj[i].size() != adj[rep].size()) pos = false;
		for (auto j: adj[i]) {
			if (adj[rep].find(j) == adj[rep].end()) pos = false;
		}
	}
	rep = *g3.begin();
	for (auto i: g3) {
		if (adj[i].size() != adj[rep].size()) pos = false;
		for (auto j: adj[i]) {
			if (adj[rep].find(j) == adj[rep].end()) pos = false;
		}
	}
	for (int i=0; i<n; i++) {
		if (g3.find(i) == g3.end() && adj[rep].find(i) == adj[rep].end()) pos = false;
		if (g3.find(i) != g3.end() && adj[rep].find(i) != adj[rep].end()) pos = false;
	}
	if (pos) {
		for (int i=0; i<n; i++) {
			if (g1.find(i) != g1.end()) {
				cout << 1 << " ";
			} else if (g2.find(i) != g2.end()) {
				cout << 2 << " ";
			} else {
				cout << 3 << " ";
			}
		}
		cout << endl;
	} else {
		cout << -1 << endl;
	}
}