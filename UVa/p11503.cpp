#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, int> h;
int par[1000000];
int size[1000000];

int root (int a) {
	while (par[a] != a) {
		par[a] = par[par[a]];
		a = par[a];
	}
	return a;
}

int merge (int a, int b) {
	int ra = root(a);
	int rb = root(b);
	if (ra != rb) {
		par[rb] = ra;
		size[ra] += size[rb];
	}
	return size[ra];
}

int main () {
	int t;
	cin >> t;
	while (t--) {
		h.clear();
		int n;
		cin >> n;
		for (int i=0; i<n; i++) {
			string a, b;
			cin >> a >> b;
			if (h.find(a) == h.end()) {
				h[a] = h.size();
				par[h[a]] = h[a];
				size[h[a]] = 1;
			}
			if (h.find(b) == h.end()) {
				h[b] = h.size();
				par[h[b]] = h[b];
				size[h[b]] = 1;
			}
			cout << merge(h[a], h[b]) << endl;
		}
	}
}