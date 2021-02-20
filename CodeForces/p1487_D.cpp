#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main () {
	vector<long long> o;
	for (long long a=2; a<100000; a++) {
		if ((a*a-1)%2 == 0) {
			long long b = (a*a-1)/2;
			long long c = b+1;
			if (a*a + b*b == c*c) o.push_back(c);
		}
	}
	int t;
	cin >> t;
	while (t--) {
		long long n;
		cin >> n;
		cout << (upper_bound(o.begin(), o.end(), n)-o.begin()) << endl;
	}
}