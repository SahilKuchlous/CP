#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int n;
vector<int> adj[26];
bool vis[26];
bool pos = true;
vector<int> ord;
set<int> hist;
bool check (int x) {
	vis[x] = true;
	hist.insert(x);
	for (auto i: adj[x]) {
		if (!vis[i]) {
			if (!check(i)) return false;
		} else {
			if (hist.find(i) != hist.end()) return false;
		}
	}
	hist.erase(x);
	return true;
}
void dfs (int x) {
	vis[x] = true;
	for (auto i: adj[x]) {
		if (vis[i]) continue;
		dfs(i);
	}
	ord.push_back(x);
}
int main () {
	cin >> n;
	string s, p = "";
	for (int i=0; i<n; i++) {
		cin >> s;
		if (p == "") {
			p = s;
			continue;
		}
		for (int j=0; j<max(s.length(), p.length()); j++) {
			if (j >= p.length()) break;
			if (j >= s.length()) {
				pos = false;
				break;
			}
			if (s[j] == p[j]) continue;
			adj[p[j]-'a'].push_back(s[j]-'a');
			break;
		}
		p = s;
	}
	for (int i=0; i<26; i++) {
		if (vis[i]) continue;
		if (!check(i)) pos = false;
	}
	if (!pos) {
		cout << "Impossible" << endl;
		return 0;
	}
	for (int i=0; i<26; i++) vis[i] = false;
	for (int i=25; i>=0; i--) {
		if (vis[i]) continue;
		dfs(i);
	}
	reverse(ord.begin(), ord.end());
	for (auto i: ord) {
		cout << (char)('a'+i);
	}
	cout << endl;
}