#include <iostream>
#include <set>
using namespace std;
int n;
set< pair<int, int> > ord;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	int s, e;
	for (int i=0; i<n; i++) {
		cin >> s >> e;
		if (ord.size() > 0 && s > ord.begin()->first) {
			pair<int, int> prv = *prev(ord.lower_bound(make_pair(s, -1)));
			if (prv.second >= s) {
				s = prv.first;
				if (prv.second > e) e = prv.second;
				ord.erase(prv);
			}
		}
		while (ord.size() > 0 && s <= prev(ord.end())->first) {
			pair<int, int> nxt = *ord.lower_bound(make_pair(s, -1));
			if (nxt.first > e) break;
			ord.erase(nxt);
			if (nxt.second > e) {
				e = nxt.second;
				break;
			}
		}
		ord.insert(make_pair(s, e));
		cout << ord.size() << " ";
	}
	cout << endl;
}