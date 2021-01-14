#include <iostream>
#include <vector>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (n <= 3) {
			cout << -1 << endl;
			continue;
		}
		vector<int> ans[4];
		ans[0] = {2, 4, 1, 3};
		ans[1] = {2, 4, 1, 5, 3};
		ans[2] = {2, 4, 1, 5, 3, 6};
		ans[3] = {2, 4, 7, 5, 1, 3, 6};
		for (int i=0; i<(n/4)-1; i++) {
			for (auto j: ans[0]) {
				cout << j+4*i << " ";
			}
		}
		for (auto j: ans[n%4]) {
			cout << j+4*(n/4-1) << " ";
		}
		cout << endl;
	}
}