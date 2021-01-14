#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main () {
	int t;
	cin >> t;
	for (int z=0; z<t; z++) {
		int n;
		cin >> n;
		vector< pair< pair<int, int>, int > > tasks;
		int si, ei;
		for (int i=0; i<n; i++) {
			cin >> si >> ei;
			tasks.push_back(make_pair(make_pair(si, ei), i));
		}
		sort(tasks.begin(), tasks.end());
		int end_a = 0, end_b = 0;
		char out[n];
		bool pos = true;
		for (auto i: tasks) {
			if (i.first.first >= end_a) {
				end_a = i.first.second;
				out[i.second] = 'C';
			} else if (i.first.first >= end_b) {
				end_b = i.first.second;
				out[i.second] = 'J';
			} else {
				pos = false;
				break;
			}
		}
		cout << "Case #" << z+1 << ": ";
		if (pos) {
			for (int i=0; i<n; i++) {
				cout << out[i];
			}
			cout << endl;
		} else {
			cout << "IMPOSSIBLE" << endl;
		}
	}
}