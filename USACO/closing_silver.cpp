#include <iostream>
#include <fstream>
#include <set>
using namespace std;
ifstream fin("closing.in");
ofstream fout("closing.out");
int n, m;
set<int> adj[200100];
bool ban[200100];
bool vis[200100];
int cnt;
void dfs (int x) {
	vis[x] = true;
	cnt++;
	for (auto i: adj[x]) {
		if (!ban[i] && !vis[i]) {
			dfs(i);
		}
	}
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	fin >> n >> m;
	int ai, bi;
	for (int i=0; i<m; i++) {
		fin >> ai >> bi;
		adj[ai].insert(bi);
		adj[bi].insert(ai);
	}
	for (int i=1; i<=n; i++) {
		ban[i] = false;
	}
	cnt = 0;
	dfs(1);
	if (cnt == n) {
		fout << "YES" << '\n';
	} else {
		fout << "NO" << '\n';
	}
	for (int i=0; i<n-1; i++) {
		fin >> ai;
		ban[ai] = true;
		for (int i=1; i<=n; i++) {
			vis[i] = false;
		}
		cnt = 0;
		for (int i=1; i<=n; i++) {
			if (!ban[i]) {
				dfs(i);
				break;
			}
		}
		if (cnt == n-i-1) {
			fout << "YES" << '\n';
		} else {
			fout << "NO" << '\n';
		}
	}
	fin >> ai;
}