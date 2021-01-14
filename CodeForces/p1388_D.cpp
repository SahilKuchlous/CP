#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int val[200000];
int p[200000];
vector<int> adj[200000];
long long o = 0;
vector<int> ord;
vector<int> extra;
long long dfs (int x) {
	long long cur = val[x];
	for (auto i: adj[x]) {
		cur += dfs(i);
	}
	o += cur;
	if (cur >= 0) {
		ord.push_back(x);
		return cur;
	}
	extra.push_back(x);
	return 0;
}
int main () {
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> val[i];
	}
	for (int i=0; i<n; i++) {
		cin >> p[i];
		p[i]--;
		if (p[i] > -2) adj[p[i]].push_back(i);
	}
	for (int i=0; i<n; i++) {
		if (p[i] == -2) {
			dfs(i);
			reverse(extra.begin(), extra.end());
			for (auto j: extra) {
				ord.push_back(j);
			}
			extra.clear();
		}
	}
	cout << o << endl;
	for (auto i: ord) {
		cout << i+1 << " ";
	}
	cout << endl;
}