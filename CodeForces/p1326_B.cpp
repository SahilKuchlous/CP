#include <iostream>
using namespace std;
int main () {
	int n;
	cin >> n;
	int a[n];
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	int o[n];
	int cur = 0;
	for (int i=0; i<n; i++) {
		if (a[i] > 0) {
			o[i] = cur+a[i];
			cur = o[i];
		} else {
			o[i] = cur+a[i];
		}
	}
	for (int i=0; i<n; i++) {
		cout << o[i] << " ";
	}
	cout << endl;
}