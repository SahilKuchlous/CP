#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		cout << k/(n-1)*n + k%(n-1) - (k%(n-1)==0?1:0) << endl;
	}
}