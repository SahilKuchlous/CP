#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int x;
		cin >> x;
		int dist = 0;
		for (int i=1; i<=100000; i++) {
			if (dist == x || dist > x+1) {
				cout << i-1 << endl;
				break;
			}
			dist += i;
		}
	}
}