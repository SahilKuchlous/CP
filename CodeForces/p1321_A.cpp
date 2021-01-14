#include <iostream>
#include <cmath>
using namespace std;
int main () {
	int n;
	cin >> n;
	int a[n];
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	int b[n];
	for (int i=0; i<n; i++) {
		cin >> b[i];
	}
	double ac = 0, bc = 0;
	for (int i=0; i<n; i++) {
		if (a[i] == 1 && b[i] == 0) ac++;
		if (a[i] == 0 && b[i] == 1) bc++;
	}
	if (ac == 0) {
		cout << -1 << endl;
	} else {
		cout << ceil((bc+1)/ac) << endl;
	}
}