#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		pair<int, int> nodes[n];
		long long cur = 0;	
		for (int i=0; i<n; i++) {
			cin >> nodes[i].first;
			nodes[i].second = -1;
			cur += nodes[i].first;
		}
		int ai, bi;
		for (int i=0; i<n-1; i++) {
			cin >> ai >> bi;
			ai--; bi--;
			nodes[ai].second++;
			nodes[bi].second++;
		}
		sort(nodes, nodes+n, greater< pair<int, int> >());
		vector<long long> o;
		o.push_back(cur);
		for (int i=0; i<n; i++) {
			for (int j=0; j<nodes[i].second; j++) {
				cur += nodes[i].first;
				o.push_back(cur);
			}
		}
		for (auto i: o) {
			cout << i << " ";
		}
		cout << endl;
	}
}