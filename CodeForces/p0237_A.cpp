#include <iostream>
#include <map>
using namespace std;
map< pair<int, int>, int > cnt;
int o = 0;
int main () {
	int n;
	cin >> n;
	int ai, bi;
	for (int i=0; i<n; i++) {
		cin >> ai >> bi;
		cnt[make_pair(ai, bi)]++;
		o = max(o, cnt[make_pair(ai, bi)]);
	}
	cout << o << endl;
}