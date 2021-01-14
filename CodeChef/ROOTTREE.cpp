#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int ai, bi;
		int in[n];
		for (int i=0; i<n; i++) {
			in[i] = 0;
		}
		for (int i=0; i<n-1; i++) {
			cin >> ai >> bi;
			bi--;
			in[bi]++;
		}
		int cost = 0;
		for (int i=0; i<n; i++) {
			cost += max(0, in[i]-1);
		}
		cout << cost << endl;
	}
}