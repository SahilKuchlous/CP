#include <iostream>
using namespace std;
int gcd (int a, int b) {
   if (b==0) return a;
   a%=b;
   return gcd(b,a);
}
int main () {
	int t;
	cin >> t;
	while (t--) {
		int r, b, k;
		cin >> r >> b >> k;
		int temp;
		if (r < b) {
			temp = r;
			r = b;
			b = temp;
		}
		int s = r-gcd(r, b);
		int c = (s-1)/b+1;
		if (c >= k) {
			cout << "REBEL" << endl;
		} else {
			cout << "OBEY" << endl;
		}
	}
}