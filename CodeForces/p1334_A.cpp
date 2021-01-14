#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		pair<int, int> logs[n];
		for (int i=0; i<n; i++) {
			cin >> logs[i].first >> logs[i].second;
		}
		bool pos = true;
		if (logs[0].first < logs[0].second) {
			pos = false;
		}
		for (int i=1; i<n; i++) {
			if (logs[i].first < logs[i-1].first) pos = false;
			if (logs[i].second < logs[i-1].second) pos = false;
			if (logs[i].first-logs[i-1].first < logs[i].second-logs[i-1].second) pos = false;
		}
		if (pos) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}