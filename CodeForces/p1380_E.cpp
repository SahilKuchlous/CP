#include <iostream>
#include <set>
using namespace std;
int n, m;
set<int> grps[200100];
int cur = 0;
int ptr[200100];
int main () {
	cin >> n >> m;
	int ai, bi;
	for (int i=0; i<n; i++) {
		cin >> ai;
		ai--;
		if (grps[ai].find(i-1) == grps[ai].end()) cur++;
		grps[ai].insert(i);
	}
	cur--;
	cout << cur << endl;
	for (int i=0; i<m; i++) {
		ptr[i] = i;
	}
	for (int i=0; i<m-1; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		int a = ptr[ai];
		int b = ptr[bi];
		if (grps[a].size() < grps[b].size()) {
			ptr[ai] = b;
			swap(a, b);
		}
		for (auto j: grps[b]) {
			if (grps[a].find(j-1) != grps[a].end() && grps[b].find(j-1) == grps[b].end()) cur--;
			if (grps[a].find(j+1) != grps[a].end()) cur--;
			grps[a].insert(j);
		}
		cout << cur << endl;
	}
}