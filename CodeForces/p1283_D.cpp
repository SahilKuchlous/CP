#include <iostream>
#include <set>
using namespace std;
int main () {
	int n, m;
	cin >> n >> m;
	int x;
	set<int> trees;
	for (int i=0; i<n; i++) {
		cin >> x;
		trees.insert(x);
	}
	int wt = 1;
	set<int> ppl;
	set<int> valid = trees;
	set<int> new_v;
	long long res = 0;
	while (true) {
		new_v.clear();
		for (auto i: valid) {
			bool good = false;
			if (trees.find(i+wt) == trees.end() && ppl.find(i+wt) == ppl.end()) {
				ppl.insert(i+wt);
				res += wt;
				good = true;
			}
			if (ppl.size() == m) {
				break;
			}
			if (trees.find(i-wt) == trees.end() && ppl.find(i-wt) == ppl.end()) {
				res += wt;
				ppl.insert(i-wt);
				good = true;
			}
			if (ppl.size() == m) {
				break;
			}
			if (good) {
				new_v.insert(i);
			}
		}
		if (ppl.size() == m) {
			break;
		}
		valid = new_v;
		wt++;
	}
	cout << res << endl;
	for (auto i: ppl) {
		cout << i << " ";
	}
	cout << endl;
}