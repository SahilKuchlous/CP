#include <iostream>
#include <set>
using namespace std;
int n, m, k;
set<int> rest[300100];
int cnt[300100];
set<int> rem;
set<int> temp;
bool used[300100];
int main () {
	cin >> n >> m >> k;
	int ai, bi;
	for (int i=0; i<m; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		rest[ai].insert(bi);
		rest[bi].insert(ai);
	}
	for (int i=1; i<n; i++) {
		rem.insert(i);
		if (rest[0].find(i) == rest[0].end()) cnt[i]++;
	}
	for (int i=1; i<n; i++) {
		if (rem.find(i) == rem.end()) continue;
		rem.erase(i);
		used[i] = true;
		while (true) {
			bool e = false;
			for (auto j: rem) {
				if (rest[i].find(j) == rest[i].end()) {
					rem.erase(j);
					cnt[i] += cnt[j];
					temp.clear();
					for (auto r: rest[j]) {
						if (rest[i].find(r) != rest[i].end()) {
							temp.insert(r);
						}
					}
					rest[i] = temp;
					e = true;
					break;
				}
			}
			if (!e) break;
		}
	}
	int c1 = 0, c2 = 0;
	bool pos = true;
	for (int i=1; i<n; i++) {
		if (used[i]) {
			if (cnt[i] == 0) pos = false;
			c1++;
			c2 += cnt[i];
		}
	}
	if (c1 > k || k > c2) pos = false;
	if (pos) {
		cout << "possible" << endl;
	} else {
		cout << "impossible" << endl;
	}
}