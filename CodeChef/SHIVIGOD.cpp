#include <iostream>
#include <iomanip>
using namespace std;
int main () {
	int t;
	cin >> t;
	for (int z=0; z<t; z++) {
		int n, b, a;
		cin >> n >> b >> a;
		long l[n];
		for (int i=0; i<n; i++) {
			cin >> l[i];
		}
		double o=0;
		for (int i=a; i<=b; i++) {
			double sum=0;
			for (int j=0; j<i; j++) {
				sum += l[j];
			}
			if (sum/i > o) {
				o = sum/i;
			}
			for (int j=0; j<n-i; j++) {
				sum -= l[j];
				sum += l[j+i];
				if (sum/i > o) {
					o = sum/i;
				}
			}
		}
		cout << fixed;
		cout << setprecision(7);
		cout << o << endl;
	}
}