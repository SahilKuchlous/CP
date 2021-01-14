#include "grader.h"
#include <vector>
using namespace std;
int n;
int cnt[1000100];
vector<int> adj[1000100];
long long size[1000100];
void dfs1 (int x, int p) {
	size[x] = cnt[x];
	for (auto i: adj[x]) {
		if (i != p) {
			dfs1(i, x);
			size[x] += size[i];
		}
	}
}
long long ot = 1e14, oi;
void dfs2 (int x, int p, int u) {
	long long ans = u;
	for (auto i: adj[x]) {
		if (i != p) {
			ans = max(ans, size[i]);
			dfs2(i, x, u+size[x]-size[i]);
		}
	}
	if (ans < ot) {
		ot = ans;
		oi = x;
	}
}
int LocateCentre (int N, int P[], int S[], int D[]) {
	n = N;
	for (int i=0; i<n; i++) {
		cnt[i] = P[i];
	}
	for (int i=0; i<n-1; i++) {
		adj[S[i]].push_back(D[i]);
		adj[D[i]].push_back(S[i]);
	}
	dfs1(0, 0);
	dfs2(0, 0, 0);
	return oi;
}