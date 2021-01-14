#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<int> adj[200000];
int col[200000];
bool o;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	int ai, bi;
	for (int i=0; i<m; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		adj[ai].push_back(bi);
		adj[bi].push_back(ai);
	}
	for (int i=0; i<n; i++) {
		bool done = false;
		for (auto j: adj[i]) {
			if (col[j]) {
				done = true;
				break;
			}
		}
		if (!done) col[i] = 1;
	}
	o = true;
	for (int i=0; i<n; i++) {
		bool good = false;
		for (auto j: adj[i]) {
			if (col[j] != col[i]) {
				good = true;
				break;
			}
		}
		if (!good) {
			o = false;
			break;
		}
	}
	if (!o) {
		cout << "NIE" << endl;
		return 0;
	}
	cout << "TAK" << endl;
	for (int i=0; i<n; i++) {
		cout << (col[i] ? 'K':'S') << endl;
	}
	cout << endl;
}