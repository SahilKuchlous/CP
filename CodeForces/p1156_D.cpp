#include <iostream>
#include <vector>
using namespace std;
#define MAXN 200005
int n;
vector< pair<int, int> > adj[MAXN];
int c0[MAXN], c1[MAXN], c01[MAXN], c10[MAXN];
long long o = 0;
void dfs (int x, int p) {
	for (auto i: adj[x]) {
		if (i.first == p) continue;
		dfs(i.first, x);
		if (i.second == 0) {
			o += 2ll*(c0[i.first]+1)+c01[i.first]+c1[i.first];
			o += 2ll*(c0[i.first]+1)*c0[x];
			o += 1ll*c0[x]*(c01[i.first]+c1[i.first]);
			o += 1ll*(c1[x]+c01[x])*(c0[i.first]+1);
			c0[x] += c0[i.first]+1;
			c01[x] += c01[i.first]+c1[i.first];
		} else {
			o += 2ll*(c1[i.first]+1)+c10[i.first]+c0[i.first];
			o += 2ll*(c1[i.first]+1)*c1[x];
			o += 1ll*c1[x]*(c10[i.first]+c0[i.first]);
			o += 1ll*(c0[x]+c10[x])*(c1[i.first]+1);
			c1[x] += c1[i.first]+1;
			c10[x] += c10[i.first]+c0[i.first];
		}
	}
}
int main () {
	cin >> n;
	int ai, bi, ci;
	for (int i=0; i<n-1; i++) {
		cin >> ai >> bi >> ci;
		ai--; bi--;
		adj[ai].push_back(make_pair(bi, ci));
		adj[bi].push_back(make_pair(ai, ci));
	}
	dfs(0, 0);
	cout << o << endl;
}