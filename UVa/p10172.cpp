#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, s, x;
		cin >> n >> s >> x;
		vector< queue<int> > v(n+1);
		int q, l;
		for (int i=1; i<=n; i++) {
			cin >> q;
			for (int j=0; j<q; j++) {
				cin >> l;
				v[i].push(l);
			}
		}
		long long o = 0;
		stack<int> c;
		int p = 1;
		while (true) {
			while (c.size() > 0 && (v[p].size() < x || c.top() == p)) {
				if (c.top() != p) {
					v[p].push(c.top());
				}
				c.pop();
				o++;
			}
			while (c.size() < s && v[p].size() > 0) {
				c.push(v[p].front());
				v[p].pop();
				o++;
			}
			bool d = false;
			if (c.size() == 0) {
				d = true;
				for (int i=1; i<=n; i++) {
					if (v[i].size() > 0) {
						d = false;
						break;
					}
				}
			}
			if (d) {
				break;
			}
			p = (p%n)+1;
			o += 2;
		}
		cout << o << endl;
	}
}