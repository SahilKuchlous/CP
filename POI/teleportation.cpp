// Overcounting
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
vector<int> adj[100000];
int ttl1 = 1, ttl2 = 1;
bool c1[100000], c2[100000];
long long o = 0;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	int ai, bi;
	for (int i=0; i<m; i++) {
		cin >> ai >> bi;
		if (ai > bi) swap(ai, bi);
		adj[ai].push_back(bi);
		adj[bi].push_back(ai);
		if (ai == 1) {
			ttl1++;
			c1[bi] = true;
		} else if (ai == 2) {
			ttl2++;
			c2[bi] = true;
		}
	}
	o = ttl1-1+ttl2-1;
	for (int i=3; i<=n; i++) {
		if (c1[i]) {
			o += ttl1-1;
		} else if (c2[i]) {
			o += ttl2-1;
		} else {
			bool ind1 = false, ind2 = false;
			for (auto j: adj[i]) {
				if (c1[j]) ind1 = true;
				if (c2[j]) ind2 = true;
			}
			if (ind1) {
				o += 2*(ttl1-1)+(n-ttl1-ttl2-1);
			} else if (ind2) {
				o += 2*(ttl2-1)+(n-ttl1-ttl2-1);
			} else {
				o += 2*max(ttl1-1, ttl2-1)+(n-ttl1-ttl2-1);
			}
		}
	}
	cout << o/2 - m << endl;
}