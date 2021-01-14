#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
#define MAXN 200005
int n;
pair<int, int> a[MAXN];
int b[MAXN];
int o[MAXN];
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i=0; i<=n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a, a+n+1);
	for (int i=0; i<n; i++) {
		cin >> b[i];
	}
	sort(b, b+n);
	multiset<int> cur;
	for (int i=1; i<=n; i++) {
		cur.insert(max(0, a[i].first-b[i-1]));
	}
	o[a[0].second] = *prev(cur.end());
	for (int i=0; i<n; i++) {
		cur.erase(cur.find(max(0, a[i+1].first-b[i])));
		cur.insert(max(0, a[i].first-b[i]));
		o[a[i+1].second] = *prev(cur.end());
	}
	for (int i=0; i<n+1; i++) {
		cout << o[i] << " ";
	}
	cout << endl;
}