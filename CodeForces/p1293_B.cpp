#include <iostream>
using namespace std;
int main () {
	int n;
	cin >> n;
	double o = 0;
	while (n > 0) {
		o += 1.0/n;
		n--;
	}
	cout << o << endl;
}