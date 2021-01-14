#include <iostream>
using namespace std;
int main () {
	char a;
	cin >> a;
	if (a-'A' <= 26) {
		cout << 'A' << endl;
	} else {
		cout << 'a' << endl;
	}
}