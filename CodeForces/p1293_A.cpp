#include <iostream>
#include <set>
#include <cmath>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, s, k;
		cin >> n >> s >> k;
		set<int> closed;
		int inp;
		for (int i=0; i<k; i++) {
			cin >> inp;
			closed.insert(inp);
		}
		int ans;
		for (int dist = 0; dist <= max(s-1, n-1); dist++) {
			if (s-dist > 0 && closed.find(s-dist) == closed.end()) {
				ans = dist;
				break;
			}
			if (s+dist <= n && closed.find(s+dist) == closed.end()) {
				ans = dist;
				break;
			}
		}
		cout << ans << endl;
	}
}