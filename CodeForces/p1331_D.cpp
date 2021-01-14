#include <iostream>
#include <string>
using namespace std;
int main () {
	string s;
	cin >> s;
	cout << ((s.at(6)-'0')%2) << endl;
}