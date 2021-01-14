#include <iostream>
using namespace std;
int main () {
	int n, m;
	cin >> n >> m;
	int sum = 0, mn = 100000;
	int inp;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> inp;
			sum += inp;
			mn = min(mn, inp);
		}
	}
	cout << sum-mn*n*m << endl;
}