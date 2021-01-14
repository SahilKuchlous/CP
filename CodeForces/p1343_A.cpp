#include <iostream>
#include <cmath>
using namespace std;
int main () {
	long long sums[40];
	sums[0] = 3;
	for (int i=1; i<40; i++) {
		sums[i] = sums[i-1]+pow(2, i+1);
	}
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		long long o = 0;
		for (int i=0; i<100000; i++) {
			if (n%sums[i] == 0) {
				cout << n/sums[i] << endl;
				break;
			}
		}
	}
}