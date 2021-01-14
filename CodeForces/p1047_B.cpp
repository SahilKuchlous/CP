#include <iostream>
using namespace std;
int main () {
	int n;
	cin >> n;
	int o = 0;
	int ai, bi;
	for (int i=0; i<n; i++) {
		cin >> ai >> bi;
		o = max(o, ai+bi);
	}
	cout << o << endl;
}