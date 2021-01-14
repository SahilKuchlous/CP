#include <iostream>
using namespace std;
int main () {
	int n;
	cin >> n;
	pair<double, double> a[n];
	for (int i=0; i<n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	if (n%2 == 1) {
		cout << "NO" << endl;
		return 0;
	}
	double x_avg = (a[0].first+a[n/2].first)/2;
	double y_avg = (a[0].second+a[n/2].second)/2;
	bool pos = true;
	for (int i=1; i<n/2; i++) {
		if ((a[i].first+a[i+n/2].first)/2 != x_avg || (a[i].second+a[i+n/2].second)/2 != y_avg) {
			pos = false;
			break;
		}
	}
	if (pos) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}