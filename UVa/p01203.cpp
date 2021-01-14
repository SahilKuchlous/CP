#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
int main () {
	string s;
	int q, p;
	priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > a;
	vector< pair<int, int> > v;
	while (true) {
		cin >> s;
		if (s == "#") {
			break;
		}
		cin >> q >> p;
		v.push_back(make_pair(q, p));
	}
	int k;
	cin >> k;
	for (auto i: v) {
		for (int j=1; j<=k; j++) {
			a.push(make_pair(i.second*j, i.first));
		}
	}
	for (int i=0; i<k; i++) {
		cout << a.top().second << endl;
		a.pop();
	}
}