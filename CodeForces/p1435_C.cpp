#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
#define MAXN 100005
int str[6];
int n;
int val[MAXN];
set< pair< long long, pair<int, int> > > ord;
long long o;
int main () {
	for (int i=0; i<6; i++) {
		cin >> str[i];
	}
	sort(str, str+6);
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> val[i];
		ord.insert(make_pair(str[0]-val[i], make_pair(i, 0)));
	}
	o = prev(ord.end())->first - ord.begin()->first;
	while (true) {
		pair< int, pair<int, int> > cur = *ord.begin();
		ord.erase(ord.begin());
		if (cur.second.second == 5) break;
		cur.second.second++;
		cur.first = str[cur.second.second]-val[cur.second.first];
		ord.insert(cur);
		o = min(o, prev(ord.end())->first - ord.begin()->first);
	}
	cout << o << endl;
}