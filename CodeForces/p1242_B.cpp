#include <iostream>
#include <vector>
#include <set>
#include <iterator>

using namespace std;
set< pair<int, int> > nadj;
set<int> nvis;

int n, m;
int main () {
	cin >> n >> m;
	int a, b;
	for (int i=0; i<m; i++) {
		cin >> a >> b;
		nadj.insert(make_pair(a, b));
		nadj.insert(make_pair(b, a));
	}
	for (int i=1; i<=n; i++) {
		nvis.insert(i);
	}
	int o = -1;
	set<int> f;
	set<int> pf;
	while (nvis.size() > 0) {
		o++;
		pf.clear();
		f.clear();
		pf.insert(*nvis.begin());
		nvis.erase(nvis.begin());
		while (pf.size() > 0) {
			// cout << pf.size() << endl;
			for (auto i: pf) {
				for (auto j: nvis) {
					if (nadj.find(make_pair(i, j)) == nadj.end()) {
						f.insert(j);
					}
				}
			}
			for (auto i: f) {
				nvis.erase(i);
			}
			pf = f;
			f.clear();
		}
	}
	cout << o << endl;
}