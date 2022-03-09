#include <iostream>
#include <set>
#include <string>
#define MAXN 1000005
#define MAXM 28
using namespace std;
int pos[MAXN][MAXM];

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string v;
	cin >> v;
	int m = v.length();
	string s;
	cin >> s;
	int n = s.length();
	set<char> cur;
	int min_len = 0;
	for (auto i: v) {
		cur.insert(i);
	}
	for (int i=0; i<n; i++) {
		cur.erase(s[i]);
		if (cur.size() == 0) {
			min_len += 1;
			for (auto j: v) {
				cur.insert(j);
			}
		}
	}
	min_len++;

	for (int i=0; i<m; i++) {
		pos[n][i] = n;
	}
	for (int i=n-1; i>=0; i--) {
		for (int j=0; j<m; j++) {
			pos[i][j] = pos[i+1][j];
		}
		pos[i][s[i]-'a'] = i;
	}

	int x;
	cin >> x;
	while (x--) {
		string q;
		cin >> q;
		if (q.length() != min_len) {
			cout << 0 << '\n';
			continue;
		}
		int p = -1;
		for (auto i: q) {
			p = pos[p+1][i-'a'];
			if (p == n) break;
		}
		if (p == n) {
			cout << 1 << '\n';
		} else {
			cout << 0 << '\n';
		}
	}
}

/*
abcd
abacdcdbadcaadbdd
*/