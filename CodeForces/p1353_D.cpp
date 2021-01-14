#include <iostream>
#include <set>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n];
		set< pair<int, pair<int, int> > > s;
		s.insert(make_pair(-(n-1), make_pair(0, n-1)));
		pair<int, int> cur;
		for (int i=1; i<=n; i++) {
			cur = (*s.begin()).second;
			s.erase(s.begin());
			int m = (cur.first+cur.second)/2;
			a[m] = i;
			if (cur.first != m) s.insert(make_pair(-(m-1-cur.first), make_pair(cur.first, m-1)));
			if (cur.second != m) s.insert(make_pair(-(cur.second-m-1), make_pair(m+1, cur.second)));
		}
		for (int i=0; i<n; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
	}
}