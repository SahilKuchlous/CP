#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<char> o;
bool comp (string &s1, string &s2) {
	for (int i=0; i<min(s1.length(), s2.length()); i++) {
		if (s1.at(i) != s2.at(i)) {
			return s1.at(i) < s2.at(i);
		}
	}
	return s1.length() < s2.length();
}
void output (string s1, string s2) {
	int p = min(s1.length(), s2.length());
	for (int i=0; i<min(s1.length(), s2.length()); i++) {
		if (s1.at(i) != s2.at(i)) {
			p = i;
			break;
		}
	}
	for (int i=p; i<s1.length(); i++) {
		o.push_back('-');
	}
	for (int i=p; i<s2.length(); i++) {
		o.push_back(s2.at(i));
	}
	o.push_back('P');
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<string> a(n);
	string longest = "";
	for (int i=0; i<n; i++) {
		cin >> a[i];
		if (a[i].length() > longest.length()) {
			longest = a[i];
		}
	}
	sort(a.begin(), a.end(), comp);
	string prev = "";
	vector<string> cur = a;
	vector<string> next;
	for (int i=0; i<longest.length(); i++) {
		for (auto j: cur) {
			if (j.length() <= i || j.at(i) != longest.at(i)) {
				output(prev, j);
				prev = j;
			} else {
				next.push_back(j);
			}
		}
		cur = next;
		next.clear();
	}
	output(prev, longest);
	cout << o.size() << '\n';
	for (auto i: o) {
		cout << i << '\n';
	}
}