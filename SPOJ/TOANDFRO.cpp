#include <iostream>
#include <string>
using namespace std;
string si;
string s;
int main () {
	while (true) {
		int n;
		cin >> n;
		if (n==0) {
			break;
		}
		cin >> si;
		s = "";
		for (int i=0; i<si.length()/n; i++) {
			if (i%2 == 0) {
				for (int j=n*i; j<n*(i+1); j++) {
					s += si.at(j);
				}
			} else {
				for (int j=n*(i+1)-1; j>n*i-1; j--) {
					s += si.at(j);
				}
			}
		}
		string sa[n];
		for (int i=0; i<n; i++) {
			sa[i] = "";
		}
		for (int i=0; i<s.length(); i++) {
			sa[i%n] += s.at(i);
		}
		for (int i=0; i<n; i++) {
			cout << sa[i];
		}
		cout << endl;
	}
}