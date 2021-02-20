#include <iostream>
#include <set>
#include <vector>
#include <string>
using namespace std;

set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

set<char> punct = {'.', ',', ';', '!', '?', '-', '(', ')'};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	string cur = "";
	vector<string> parts;
	for (auto i: s) {
		cur += i;
		if (vowels.find(i) != vowels.end()) {
			parts.push_back(cur);
			cur = "";
		}
		if (cur[0] == 'n' && cur.length() > 1) {
			parts.push_back("n");
			cur = cur.substr(1, cur.length()-1);
		}
		if (punct.find(i) != punct.end()) {
			parts.push_back(cur);
			cur = "";
		}
	}
	if (cur != "") {
		parts.push_back(cur);
	}
	vector<string> o;
	for (auto i: parts) {
		if (i.size() == 1) {
			o.push_back(i);
			continue;
		}
		if (i[0] == i[1]) {
			o.push_back(i.substr(0, 1));
			o.push_back(i.substr(1, i.length()-1));
			continue;
		}
		o.push_back(i);
	}
	for (auto i: o) {
		cout << i << " ";
	}
	cout << endl;
}