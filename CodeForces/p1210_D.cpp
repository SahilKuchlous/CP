#include <iostream>
#include <vector>
#include <set>
using namespace std;
int n, m;
vector<int> org[100100];
vector<int> inc[100100];
long long out[100100];
long long ttl = 0;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	int ai, bi;
	for (int i=0; i<m; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		org[ai].push_back(bi);
		org[bi].push_back(ai);
	}
	for (int i=0; i<n; i++) {
		for (auto j: org[i]) {
			if (j > i) {
				inc[i].push_back(j);
			} else {
				out[i]++;;
			}
		}
		ttl += inc[i].size()*out[i];
	}
	cout << ttl << endl;
	int q;
	cin >> q;
	int root;
	while (q--) {
		cin >> root;
		root--;
		ttl -= inc[root].size()*out[root];
		out[root] += inc[root].size();
		for (auto i: inc[root]) {
			ttl -= inc[i].size()*out[i];
			inc[i].push_back(root);
			out[i]--;
			ttl += inc[i].size()*out[i];
		}
		inc[root].clear();
		cout << ttl << '\n';
	}
}