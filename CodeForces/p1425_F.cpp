#include <iostream>
using namespace std;
int main () {
	int n;
	cin >> n;
	int psum[n];
	for (int i=1; i<n; i++) {
		cout << "?" << " " << 1 << " " << i+1 << endl;
		cin >> psum[i];
	}
	cout << "? 2 3" << endl;
	int temp;
	cin >> temp;
	psum[0] = psum[2]-temp;
	cout << "! " << psum[0] << " ";
	for (int i=1; i<n; i++) {
		cout << psum[i]-psum[i-1] << " ";
	}
	cout << endl;
}