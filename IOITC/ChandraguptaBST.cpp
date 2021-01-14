#include <iostream>
#include <set>
#include <algorithm>
#define MOD 1000000007
using namespace std;
int n;
int val[300100];
set< pair<int, int> > ord;
int ind[300100];
bool l[300100], r[300100];
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> val[i];
	}
	ord.insert(make_pair(val[0], 0));
	ind[0] = 1;
	for (int i=1; i<n; i++) {
		set< pair<int, int> >::iterator fwd = ord.lower_bound(make_pair(val[i], i));
		if (fwd != ord.end() && l[fwd->second] == false) {
			ind[i] = (2ll*ind[fwd->second])%MOD;
			l[fwd->second] = true;
		} else {
			fwd = prev(fwd);
			ind[i] = (2ll*ind[fwd->second]+1)%MOD;
			r[fwd->second] = true;
		}
		ord.insert(make_pair(val[i], i));
	}
	for (int i=0; i<n; i++) {
		cout << ind[i] << " ";
	}
	cout << endl;
}