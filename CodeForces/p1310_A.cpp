#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 200005
int n;
int a[MAXN], t[MAXN];
vector< pair<int, int> > ord;
multiset<int> cur;
int ptr = 0;
int pos = 0;
long long sum = 0;
long long o = 0;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	for (int i=0; i<n; i++) {
		cin >> t[i];
	}
	for (int i=0; i<n; i++) {
		ord.push_back(make_pair(a[i], t[i]));
	}
	sort(ord.begin(), ord.end());
	while (ptr < n) {
		if (cur.size() == 0) {
			pos = ord[ptr].first;
		}
		while (ord[ptr].first == pos) {
			cur.insert(-ord[ptr].second);
			sum += ord[ptr].second;
			ptr++;
		}
		sum += *cur.begin();
		cur.erase(cur.begin());
		o += sum;
		pos++;
	}
	while (cur.size() > 0) {
		sum += *cur.begin();
		cur.erase(cur.begin());
		o += sum;
		pos++;
	}
	cout << o << endl;
}