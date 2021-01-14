#include <iostream>
#include <string>
#include <map>
#include <unordered_set>
using namespace std;
int main () {
	map< pair<string, string>, int > id;
	string s1, s2, s3, s4;
	int cur = 0;
	while (true) {
		cur++;
		cin >> s1;
		if (s1 == "----------") {
			break;
		}
		cin >> s2 >> s3 >> s4;
		id[make_pair(s1, s2)] = cur;
		id[make_pair(s3, s4)] = cur;
	}
	unordered_set<int> stat;
	while (true) {
		cin >> s1;
		if (s1 == "END") {
			break;
		}
		if (s1 == "+") {
			cin >> s2 >> s3;
			stat.insert(id[make_pair(s2, s3)]);
			continue;
		}
		if (s1 == "-") {
			cin >> s2 >> s3;
			stat.erase(id[make_pair(s2, s3)]);
			continue;
		}
		if (s1 == "FIND") {
			cin >> s2 >> s3;
			if (stat.find(id[make_pair(s2, s3)]) == stat.end()) {
				cout << 404 << endl;
			} else {
				cout << "FOUND" << endl;
			}
			continue;
		}
		if (s1 == "UNION") {
			cout << stat.size() << endl;
			continue;
		}
	}
}