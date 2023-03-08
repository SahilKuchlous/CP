// Chipotgang 618311

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
set<char> vals;
vector<char> cnt[26][26];
int main () {
	int n;
	cin >> n;
	string a[n];
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	for (auto s: a) {
		if (s[0] != s[1] && s[0] != s[2] && s[1] != s[2]) cnt[s[0]-'a'][s[1]-'a'].push_back(s[2]);
	}
	for (int i=0; i<26; i++) {
		for (int j=0; j<26; j++) {
			sort(cnt[i][j].begin(), cnt[i][j].end());
			unique(cnt[i][j].begin(), cnt[i][j].end());
		}
	}
	vector< vector<string> > options;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			vals.clear();
			for (auto k: a[i]) {
				vals.insert(k);
			}
			for (auto k: a[j]) {
				vals.insert(k);
			}
			if (vals.size() != 6) continue;
			if (cnt[a[i][0]-'a'][a[j][0]-'a'].size() == 0) continue;
			if (cnt[a[i][1]-'a'][a[j][1]-'a'].size() == 0) continue;
			if (cnt[a[i][2]-'a'][a[j][2]-'a'].size() == 0) continue;
			for (auto l1: cnt[a[i][0]-'a'][a[j][0]-'a']) {
				if (vals.find(l1) != vals.end()) continue;
				for (auto l2: cnt[a[i][1]-'a'][a[j][1]-'a']) {
					if (cnt[l1-'a'][l2-'a'].size() == 0) continue;
					if (l1 == l2) continue;
					if (vals.find(l2) != vals.end()) continue;
					for (auto l3: cnt[a[i][2]-'a'][a[j][2]-'a']) {
						if (l3 == l1 || l3 == l2) continue;
						if (vals.find(l3) != vals.end()) continue;
						if (binary_search(cnt[l1-'a'][l2-'a'].begin(), cnt[l1-'a'][l2-'a'].end(), l3)) {
							string s = "";
							s.push_back(l1); s.push_back(l2); s.push_back(l3);
							options.push_back({a[i], a[j], s});
						}
					}
				}
			}
		}
	}
	long long ans = 0;
	for (auto i: options) {
		vals.clear();
		for (auto j: i) {
			for (auto k: j) {
				vals.insert(k);
			}
		}
		if (vals.size() != 9) continue;
		if (!binary_search(cnt[i[0][0]-'a'][i[1][1]-'a'].begin(), cnt[i[0][0]-'a'][i[1][1]-'a'].end(), i[2][2])) continue;
		if (!binary_search(cnt[i[0][2]-'a'][i[1][1]-'a'].begin(), cnt[i[0][2]-'a'][i[1][1]-'a'].end(), i[2][0])) continue;
		ans++;
	}
	cout << ans << endl;
}