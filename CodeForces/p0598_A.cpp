#include <iostream>
#include <cmath>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		long long n;
		cin >> n;
		long long o = n*(n+1)/2;
		for (long long i=1; i<=n; i*=2) {
			o -= 2*i;
		}
		cout << o << endl;
	}
}