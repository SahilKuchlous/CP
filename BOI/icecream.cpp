#include <iostream>
#include <set>
using namespace std;
int n, m;
set<int> ban[210];
int o = 0;
int main () {
	cin >> n >> m;
	int ai, bi;
	for (int i=0; i<m; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		ban[ai].insert(bi);
		ban[bi].insert(ai);
	}
	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			if (ban[i].find(j) != ban[i].end()) continue;
			for (int k=j+1; k<n; k++) {
				if (ban[i].find(k) != ban[i].end()) continue;
				if (ban[j].find(k) != ban[j].end()) continue;
				o++;
			}
		}
	}
	cout << o << endl;
}