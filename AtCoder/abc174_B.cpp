#include <iostream>
using namespace std;
int main () {
	long long n, d;
	cin >> n >> d;
	int o = 0;
	long long x, y;
	for (int i=0; i<n; i++) {
		cin >> x >> y;
		if (x*x+y*y <= d*d) o++;
	}
	cout << o << endl;
}