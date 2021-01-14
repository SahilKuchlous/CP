#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
using namespace std;
int main () {
	int t;
	cin >> t;
	for (int z=1; z<=t; z++) {
		int u;
		cin >> u;
		long long ai;
		string bi;
		long long freq[26];
		bool pos[26];
		for (int i=0; i<26; i++) {
			freq[i] = 0;
			pos[i] = false;
		}
		vector<string> info;
		for (int i=0; i<10000; i++) {
			cin >> ai >> bi;
			info.push_back(bi);
			freq[bi.at(0)-'A'] += 1;
			for (auto j: bi) {
				pos[j-'A'] = true;
			}
		}
		char o[10];
		for (auto i: info) {
			pos[i.at(0)-'A'] = false;
		}
		for (int i=0; i<26; i++) {
			if (pos[i]) {
				o[0] = 'A'+i;
				freq[i] = -1;
				break;
			}
		}
		for (int i=1; i<10; i++) {
			long long max_freq = 0, best_char = 0;
			for (int j=0; j<26; j++) {
				if (freq[j] > max_freq) {
					max_freq = freq[j];
					best_char = j;
				}
			}
			o[i] = 'A'+best_char;
			freq[best_char] = -1;
		}
		cout << "Case #" << z << ": ";
		for (int i=0; i<10; i++) {
			cout << o[i];
		}
		cout << endl;
	}
}