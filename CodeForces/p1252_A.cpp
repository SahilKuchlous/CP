#include <iostream>
using namespace std;
int main () {
	int n;
	cin >> n;
	int x;
	for (int i=0; i<n; i++) {
		cin >> x;
		cout << n-x+1 << " ";
	}
	cout << endl;
}