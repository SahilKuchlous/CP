#include <iostream>
#include <vector>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n];
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}
		int o = 1;
		vector<int> seq;
		seq.push_back(a[0]);
		bool inc = true;
		if (a[1] < a[0]) inc = false;
		for (int i=1; i<n-1; i++) {
			if ((a[i+1] < a[i] && inc) || (a[i+1] > a[i] && !inc)) {
				seq.push_back(a[i]);
				inc = !inc;
				o++;
			}
		}
		o++;
		seq.push_back(a[n-1]);
		cout << o << endl;
		for (auto i: seq) cout << i << " ";
		cout << endl;
	}
}