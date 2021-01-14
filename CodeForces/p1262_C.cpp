#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n, k;
string s;
void reverse (int a, int b) {
	string ns = "";
	for (int i=0; i<a; i++) {
		ns += s[i];
	}
	for (int i=b; i>=a; i--) {
		ns += s[i];
	}
	for (int i=b+1; i<n; i++) {
		ns += s[i];
	}
	s = ns;
}
int main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		k--;
		cin >> s;
		vector< pair<int, int> > o;
		int x = 0;
		while (k > 0) {
			if (x%2 == 0) {
				if (s[x] != '(') {
					for (int i=x+1; i<n; i++) {
						if (s[i] == '(') {
							o.push_back(make_pair(x, i));
							reverse(x, i);
							break;
						}
					}
				}
			} else {
				if (s[x] != ')') {
					for (int i=x+1; i<n; i++) {
						if (s[i] == ')') {
							o.push_back(make_pair(x, i));
							reverse(x, i);
							break;
						}
					}
				}
				k--;
			}
			x++;
		}
		for (int i=x; i<x+(n-x)/2; i++) {
			if (s[i] != '(') {
				for (int j=i+1; j<n; j++) {
					if (s[j] == '(') {
						o.push_back(make_pair(i, j));
						reverse(i, j);
						break;
					}
				}
			}
		}
		for (int i=x+(n-x)/2; i<n; i++) {
			if (s[i] != ')') {
				for (int j=i+1; j<n; j++) {
					if (s[j] == ')') {
						o.push_back(make_pair(i, j));
						reverse(i, j);
						break;
					}
				}
			}
		}
		cout << o.size() << endl;
		for (auto i: o) {
			cout << i.first+1 << " " << i.second+1 << endl;
		}
	}
}