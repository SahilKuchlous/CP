#include <iostream>
#include <vector>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> adj[n+1];
		int c, ind;
		for (int i=1; i<=n; i++) {
			cin >> c;
			for (int j=0; j<c; j++) {
				cin >> ind;
				adj[i].push_back(ind);
			}
		}
		bool vis[n+1];
		for (int i=1; i<=n; i++) {
			vis[i] = false;
		}
		bool done;
		int bad = -1;
		for (int i=1; i<=n; i++) {
			done = false;
			for (auto j: adj[i]) {
				if (!vis[j]) {
					vis[j] = true;
					done = true;
					break;
				}
			}
			if (!done) {
				bad = i;
			}
		}
		if (bad == -1) {
			cout << "OPTIMAL" << endl;
		} else {
			cout << "IMPROVE" << endl;
			for (int i=1; i<=n; i++) {
				if (!vis[i]) {
					cout << bad << " " << i << endl;
					break;
				}
			}
		}
	}
}