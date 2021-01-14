/*
ID: sahilku4
LANG: C
TASK: ride
*/
#include <iostream>
using namespace std;
int main () {
	string s1, s2;
	cin >> s1 >> s2;
	long long n1, n2;
	n1 = 1;
	n2 = 1;
	for (int i=0; i<6; i++) {
		n1 *= s1.at(i)-64;
		n2 *= s2.at(i)-64;
	}
	if (n1%47 == n2%47) {
		cout << "GO" << endl;
	} else {
		cout << "STAY" << endl;
	}
	return 0;
}