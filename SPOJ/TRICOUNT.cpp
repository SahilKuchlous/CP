#include <iostream>
#include <cmath>
using namespace std;
int main () {
	int t;
	cin >> t;
	for (int i=0; i<t; i++) {
		int n;
		cin >> n;
		cout << floor(n*(n+2)*(2*n+1)/8) << endl;
	}
}