#include <iostream>
#include <vector>
using namespace std;
int main () {
	int n, k;
	cin >> n >> k;
	vector< pair<int, int> > o;
	for (int i=1; i<=k; i++) {
		for (int j=i+1; j<=k; j++) {
			o.push_back(make_pair(i, j));
			o.push_back(make_pair(j, i));
			if (o.size() >= n) break;
		}
		if (o.size() >= n) break;
	}
	if (o.size() >= n) {
		cout << "YES" << endl;
		for (int i=0; i<n; i++) {
			cout << o[i].first << " " << o[i].second << endl;
		}
	} else {
		cout << "NO" << endl;
	}
}