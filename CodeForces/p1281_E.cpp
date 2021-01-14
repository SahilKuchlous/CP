#include <iostream>
#include <vector>
using namespace std;
int n;
vector< pair<int, int> > adj[200100];
bool done[200100];
long long og = 0, ob = 0;
int size[200100];
int cent;
void reset () {
	for (int i=0; i<2*n; i++) {
		adj[i].clear();
		done[i] = false;
	}
	og = ob = 0;
}
void dfs1 (int x, int p) {
	int cnt = 0;
	for (auto i: adj[x]) {
		if (i.first != p) {
			dfs1(i.first, x);
			if (!done[i.first]) {
				og += i.second;
				cnt++;
			}
		}
	}
	done[x] = (cnt%2==1);
}
void calc_size (int x, int p) {
	size[x] = 1;
	for (auto i: adj[x]) {
		if (i.first != p) {
			calc_size(i.first, x);
			size[x] += size[i.first];
		}
	}
}
void find_cent () {
	cent = 0;
	int prev = 0;
	bool done;
	while (true) {
		done = true;
		for (auto i: adj[cent]) {
			if (i.first != prev && size[i.first] > n) {
				prev = cent;
				cent = i.first;
				done = false;
				break;
			}
		}
		if (done) break;
	}
}
void dfs2 (int x, int p) {
	for (auto i: adj[x]) {
		if (i.first != p) {
			dfs2(i.first, x);
			ob += 1ll*i.second*size[i.first];
		}
	}
}
int main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		reset();
		int ai, bi, wi;
		for (int i=0; i<2*n-1; i++) {
			cin >> ai >> bi >> wi;
			ai--; bi--;
			adj[ai].push_back(make_pair(bi, wi));
			adj[bi].push_back(make_pair(ai, wi));
		}
		dfs1(0, 0);
		calc_size(0, 0);
		find_cent();
		calc_size(cent, cent);
		dfs2(cent, cent);
		cout << og << " " << ob << endl;
	}
}