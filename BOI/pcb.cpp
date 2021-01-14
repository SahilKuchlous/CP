#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int n;
pair<int, int> a[100000];
set<int> grps;
int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	sort(a, a+n);
	grps.insert(a[0].second);
	for (int i=1; i<n; i++) {
		if (a[i].second < *grps.begin()) {
			grps.insert(a[i].second);
			continue;
		}
		grps.erase(prev(grps.lower_bound(a[i].second)));
		grps.insert(a[i].second);
	}
	cout << grps.size() << endl;
}