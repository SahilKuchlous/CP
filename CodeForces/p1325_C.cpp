#include <iostream>
#include <vector>
using namespace std;
int n;
vector< pair<int, int> > adj[100100];
int bp, fp;
int wts[100100];
void dfs (int x, int p) {
	for (auto i: adj[x]) {
		if (i.first != p) {
			if (adj[i.first].size() == 1 || adj[x].size() == 1) {
				wts[i.second] = bp;
				bp++;
				dfs(i.first, x);
			} else {
				wts[i.second] = fp;
				fp--;
				dfs(i.first, x);
			}
		}
	}
}
int main () {
	cin >> n;
	int ai, bi;
	for (int i=0; i<n-1; i++) {
		cin >> ai >> bi;
		adj[ai].push_back(make_pair(bi, i));
		adj[bi].push_back(make_pair(ai, i));
	}
	bp = 0;
	fp = n-2;
	dfs(1, 1);
	for (int i=0; i<n-1; i++) {
		cout << wts[i] << endl;
	}
}