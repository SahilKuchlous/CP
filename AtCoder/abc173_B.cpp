#include <iostream>
#include <map>
using namespace std;
int main () {
	map< char, int > freq;
	int n;
	cin >> n;
	string a;
	for (int i=0; i<n; i++) {
		cin >> a;
		freq[a[0]]++;
	}
	cout << "AC x " << freq['A'] << endl;
	cout << "WA x " << freq['W'] << endl;
	cout << "TLE x " << freq['T'] << endl;
	cout << "RE x " << freq['R'] << endl;
}