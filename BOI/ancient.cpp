#include <iostream>
#include <string>
#include <set>
using namespace std;
int vc, cc, ve, ce;
string inp;
int type[26];
long long memo[20*30*6*6];
long long solve (int pos, int prev_char, int char_freq, int type_freq) {
	if (type[prev_char] == 0 && type_freq > cc) return 0;
	if (type[prev_char] == 1 && type_freq > vc) return 0;
	if (type[prev_char] == 0 && char_freq > ce) return 0;
	if (type[prev_char] == 1 && char_freq > ve) return 0;
	if (pos == inp.size()) return 1;
	if (memo[pos*30*6*6+prev_char*6*6+char_freq*6+type_freq] != -1) return memo[pos*30*6*6+prev_char*6*6+char_freq*6+type_freq];
	long long o = 0;
	if (inp.at(pos) == '*') {
		for (int i=0; i<26; i++) {
			if (i == prev_char) {
				o += solve(pos+1, i, char_freq+1, type_freq+1);
			} else if (type[i] == type[prev_char]) {
				o += solve(pos+1, i, 1, type_freq+1);
			} else {
				o += solve(pos+1, i, 1, 1);
			}
		}
	} else {
		int i = inp.at(pos)-'a';
		if (i == prev_char) {
			o += solve(pos+1, i, char_freq+1, type_freq+1);
		} else if (type[i] == type[prev_char]) {
			o += solve(pos+1, i, 1, type_freq+1);
		} else {
			o += solve(pos+1, i, 1, 1);
		}
	}
	memo[pos*30*6*6+prev_char*6*6+char_freq*6+type_freq] = o;
	return o;
}
int main () {
	cin >> ve >> vc >> ce >> cc;
	cin >> inp;
	type['a'-'a'] = type['e'-'a'] = type['i'-'a'] = type['o'-'a'] = type['u'-'a'] = 1;
	for (int i=0; i<20*30*6*6; i++) {
		memo[i] = -1;
	}
	long long ans = solve(0, 0, 0, 0);
	cout << ans << endl;
}