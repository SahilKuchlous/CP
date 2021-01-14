#include <iostream>
#include <cmath>
using namespace std;
int main () {
	int k;
	cin >> k;
	int a[3][3];
	a[1][0] = a[2][0] = a[2][1] = 0;
	a[0][0] = a[0][1] = a[1][2] = (1 << (int)(floor(log2(k))+1))+k;
	a[1][1] = (1 << (int)(floor(log2(k))+1));
	a[0][2] = a[2][2] = k;
	cout << 3 << " " << 3 << endl;
	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	} 
}