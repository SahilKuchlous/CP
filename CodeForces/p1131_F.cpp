#include <iostream>
#include <vector>
#define MAXN 200000
using namespace std;
int n;
int par[MAXN];
vector<int> seq[MAXN];
int root (int x) {
	if (x == par[x]) return x;
	par[x] = par[par[x]];
	return root(par[x]);
}
void merge (int x, int y) {
	int rx = root(x), ry = root(y);
	if (seq[rx].size() < seq[ry].size()) swap(rx, ry);
	for (auto i: seq[ry]) {
		seq[rx].push_back(i);
	}
	par[ry] = rx;
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; i++) {
		par[i] = i;
		seq[i] = {i};
	}
	int ai, bi;
	for (int i=0; i<n-1; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		merge(ai, bi);
	}
	for (auto i: seq[root(0)]) {
		cout << i+1 << " ";
	}
	cout << endl;
}