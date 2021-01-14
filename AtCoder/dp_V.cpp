#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, MOD;
vector<int> adj[100100];
long long down[100100];
void dfs1 (int x, int p) {
	down[x] = 1;
	adj[x].erase(remove(adj[x].begin(), adj[x].end(), p), adj[x].end());
	for (auto i: adj[x]) {
		dfs1(i, x);
		down[x] = (down[x]*(down[i]+1))%MOD;
	}
}
long long up[100100];
long long pre[100100], suf[100100];
void dfs2 (int x, int p) {
	pre[0] = suf[adj[x].size()] = 1;
	for (int i=0; i<adj[x].size(); i++) {
		pre[i+1] = (pre[i]*(down[adj[x][i]]+1))%MOD;
	}
	for (int i=adj[x].size(); i>0; i--) {
		suf[i-1] = (suf[i]*(down[adj[x][i-1]]+1))%MOD;
	}
	for (int i=0; i<adj[x].size(); i++) {
		up[adj[x][i]] = ((up[x]*((pre[i]*suf[i+1])%MOD))+1)%MOD;
	}
	for (auto i: adj[x]) {
		dfs2(i, x);
	}
}
int main () {
	cin >> n >> MOD;
	int ai, bi;yyyyyyy
	for (int i=0; i<n-1; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		adj[ai].push_back(bi);
		adj[bi].push_back(ai);
	}
	dfs1(0, -1);
	up[0] = 1;
	dfs2(0, -1);
	for (int i=0; i<n; i++) cout << (up[i]*down[i])%MOD << endl;
}