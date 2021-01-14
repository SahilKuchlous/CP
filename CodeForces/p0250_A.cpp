#include <iostream>
#include <vector>
using namespace std;
int n, x, t, a[105], p;
int main () {
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		if( x < 0) t++;
		if (t == 3) p++, t = 1;
		a[p]++;
	}
	cout << p+1 << endl;
	for (int i=0; i<=p; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}