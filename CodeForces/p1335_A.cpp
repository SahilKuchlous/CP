#include <iostream>
#include <cmath>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (n%2 == 0) n--;
		cout << n/2 << endl;
	}
}