#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main () {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int t = 3;
	vector<int> o1;
	int c1=  0;
	string s1 = s;
	string s1n;
	while (t--) {
		for (int i=0; i<n-1; i++) {
			if (s1.at(i) == 'W') {
				c1++;
				o1.push_back(i+1);
				s1n = s1.substr(0, i) + "B";
				if (s1.at(i+1) == 'W') {
					s1n += "B";
				} else {
					s1n += "W";
				}
				s1n += s1.substr(i+2, s1.size()-i+2);
				s1 = s1n;
			}
		}
	}
	bool done = true;
	for (int i=0; i<n; i++) {
		if (s1.at(i) != 'B') {
			done = false;
		}
	}
	if (!done) {
		c1 = -1;
	}
	t = 3;
	vector<int> o2;
	int c2 = 0;
	string s2 = s;
	string s2n;
	while (t--) {
		for (int i=0; i<n-1; i++) {
			if (s2.at(i) == 'B') {
				c2++;
				o2.push_back(i+1);
				s2n = s2.substr(0, i) + "W";
				if (s2.at(i+1) == 'W') {
					s2n += "B";
				} else {
					s2n += "W";
				}
				s2n += s2.substr(i+2, s2.size()-i+2);
				s2 = s2n;
			}
		}
	}
	done = true;
	for (int i=0; i<n; i++) {
		if (s2.at(i) != 'W') {
			done = false;
		}
	}
	if (!done) {
		c2 = -1;
	}
	if (c1 != -1) {
		cout << c1 << endl;
		for (auto i: o1) {
			cout << i << " ";
		}
		if (c1 > 0) {
			cout << endl;	
		}
	} else {
		if (c2 != -1) {
			cout << c2 << endl;
			for (auto i: o2) {
				cout << i << " ";
			}
			if (c2 > 0) {
				cout << endl;	
			}
		} else {
			cout << -1 << endl;
		}
	}
}