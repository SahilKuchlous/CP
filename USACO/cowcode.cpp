#include <iostream>
#include <fstream>
#include <string> 
using namespace std;
ifstream fin("cowcode.in");
ofstream fout("cowcode.out");
int main () {
	string s;
	long long n;
	cin >> s >> n;
	n--;
	long long high = s.length();
	while (high < n+1) {
		high = high*2;
	}
	int ind = n%s.length();
	while (high >= s.length()) {
		if (n >= high) {
			n -= high;
			ind = (s.length()+ind-1)%s.length();
		}
		high /= 2;
	}
	cout << s.at(ind) << endl;
}