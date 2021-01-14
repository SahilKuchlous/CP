#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main () {
	long long n;
	cin >> n;
	string s;
	cin >> s;
	long long c = n;
	vector<int> v;
	char cur = s[0];
	int cnt = 1;
	for (int i=1; i<n; i++) {
		if (s[i] == cur) {
			cnt++;
		} else {
			v.push_back(cnt);
			cnt = 1;
			cur = s[i];
		}
	}
	v.push_back(cnt);
	c += v.size()-1;
	if (v.size() > 1) {
		c += v[0]-1;
		c += v[v.size()-1]-1;
	}
	for (int i=1; i<v.size()-1; i++) {
		c += 2*(v[i]-1);
	}
	long long o = n*(n+1)/2 - c;
	cout << o << endl;
}