#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, k;
string s;
vector<int> cur;
vector<int> cnt = {0};
int pos = 0;
vector< vector<int> > o;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k >> s;
	for (int i=0; i<n; i++) {
		cur.push_back(i);
		if (s[i] == 'b') {
			cnt[pos]++;
		} else {
			cnt.push_back(0);
			pos++;
		}
		if (pos == 0 || cnt[pos]+cnt[pos-1] < k) continue;
		o.push_back({});
		for (int i=0; i<k+1; i++) {
			o[o.size()-1].push_back(cur.back());
			cur.pop_back();
		}
		cnt[pos-1] -= k-cnt[pos];
		cnt.pop_back();
		pos--;
	}
	reverse(o.begin(), o.end());
	for (int i=0; i<o.size(); i++) {
		reverse(o[i].begin(), o[i].end());
		for (auto j: o[i]) cout << j+1 << " ";
		cout << endl;
	}
}