#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main () {
	int n;
	cin >> n;
	string s;
	for (int i=0; i<n; i++) {
		cin >> s;
		cout << s << ": F" << endl;
	}
}