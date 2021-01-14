#include <iostream>
#include <set>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		char a[n];
		int freq[26];
		int cnt[26];
		for (int i=0; i<26; i++) {
			freq[i] = 0;
			cnt[i] = 1;
		}
		for (int i=0; i<n; i++) {
			cin >> a[i];
			freq[a[i]-'a']++;
		}
		set< pair<int, int> > opts;
		for (int i=0; i<26; i++) {
			opts.insert(make_pair(-freq[i], i));
		}
		int o = 0;
		for (int i=1; i<=k; i++) {
			pair<int, int> top = *opts.begin();
			opts.erase(opts.begin());
			cnt[top.second]++;
			opts.insert(make_pair(-freq[top.second]/cnt[top.second], top.second));
			if (k%i == 0) {
				o = max(o, -top.first*i);
			}
		}
		cout << o << endl;
	}
}