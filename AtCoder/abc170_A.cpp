#include <iostream>
using namespace std;
int main () {
	int arr[5];
	for (int i=0; i<5; i++) {
		cin >> arr[i];
		if (arr[i] == 0) {
			cout << i+1 << endl;
			return 0;
		}
	}
}