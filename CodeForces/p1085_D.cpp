#include <iostream>
#include <iomanip>
using namespace std;
int main () {
	cout << fixed;
	cout << setprecision(8);
	int n;
	double s;
	cin >> n >> s;
	int count[n+1];
	for (int i=0; i<=n; i++) {
		count[i] = 0;
	}
	int a, b;
	for (int i=0; i<n-1; i++) {
		cin >> a >> b;
		count[a]++;
		count[b]++;
	}
	double l = 0;
	for (int i=1; i<=n; i++) {
		if (count[i] == 1) l++;
	}
	cout << 2*s/l << endl;
}