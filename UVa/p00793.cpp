#include <iostream>
#include <string>
using namespace std;
int v[100000];
int root (int x) {
	if (v[x] != x) {
		return root(v[x]);
	}
	return x;
}
void uni (int a, int b) {
	int ra = root(a);
	int rb = root(b);
	v[ra] = rb;
}
bool find (int a, int b) {
	if (root(a) == root(b)) {
		return true;
	} else {
		return false;
	}
}
int main () {
	int t;
	string s, inp;
	getline(cin, s);
	t = stoi(s);
	getline(cin, s);
	while (t--) {
		int n;
		getline(cin, s);
		n = stoi(s);
		int o1 = 0, o2 = 0;
		for (int i=0; i<n; i++) {
			v[i] = i;
		}
		while (true) {
			getline(cin, inp);
			if (inp == "") {
				break;
			}
			s = "";
			char q;
			int a, b;
			int x = 0;
			for (auto i: inp) {
				if (i == ' ') {
					if (x == 0) {
						q = s[0];
					} else {
						a = stoi(s);
					}
					s = "";
					x++;
				} else {
					s += i;
				}
			}
			b = stoi(s);
			a--;
			b--;
			if (q == 'c') {
				uni(a, b);
			} else if (q == 'q') {
				if (find(a, b)) {
					o1++;
				} else {
					o2++;
				}
			}
		}
		cout << o1 << "," << o2 << endl;
		if (t > 0) {
			cout << endl;
		}
	}
}