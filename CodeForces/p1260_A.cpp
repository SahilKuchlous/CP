#include <iostream>
#include <cmath>
using namespace std;
int main () {
	int n;
	cin >> n;
	long long o;
	int c, s;
	for (int i=0; i<n; i++) {
		o = 0;
		cin >> c >> s;
		o += pow(s/c+1, 2)*(s%c);
		o += pow(s/c, 2)*(c-(s%c));
		cout << o << endl;
	}
}