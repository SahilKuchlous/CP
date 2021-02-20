#include <iostream>
using namespace std;
int main () {
	cout << 500000 << " " << 100 << " " << 500 << '\n';
	for (int i=0; i<500000; i++) {
		cout << 100 << " ";
	}
	cout << '\n';
	for (int i=0; i<500000; i++) {
		cout << 100 << " ";
	}
	cout << '\n';
	cout << 500000 << '\n';
	for (int i=0; i<500000; i++) {
		cout << i << '\n';
	}
}