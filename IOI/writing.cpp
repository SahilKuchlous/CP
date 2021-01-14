#include <iostream>
#include <map>
using namespace std;
int main () {
	int k, n;
	cin >> k >> n;
	map<char, int> req;
	char inp;
	for (int i=0; i<k; i++) {
		cin >> inp;
		req[inp]++;
	}
	char s[n];
	for (int i=0; i<n; i++) {
		cin >> s[i];
	}
	int missing = k;
	map<char, int> cur;
	int o = 0;
	for (int i=0; i<k; i++) {
		if (cur[s[i]] < req[s[i]]) missing--;
		cur[s[i]]++;
	}
	if (missing == 0) o++;
	for (int i=k; i<n; i++) {
		if (cur[s[i-k]] <= req[s[i-k]]) missing++;
		cur[s[i-k]]--;
		if (cur[s[i]] < req[s[i]]) missing--;
		cur[s[i]]--;
		if (missing == 0) o++;
	}
	cout << o << endl;
}