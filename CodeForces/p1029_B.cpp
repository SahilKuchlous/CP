#include <iostream>
using namespace std;
int main () {
	int n;
	cin >> n;
	int a[n];
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	int c=1, o=1;
	for (int i=0; i<n-1; i++) {
		if (a[i+1] <= 2*a[i]) {
			c++;
			o = max(o, c);
		} else {
			c = 1;
		}
	}
	cout << o << endl;
}