#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ifstream fin("necklace.in");
ofstream fout("necklace.out");
int main () {
	string ai, bi;
	cin >> ai >> bi;
	int n = ai.length();
	int m = bi.length();
	char text[n];
	for (int i=0; i<n; i++) {
		text[i] = ai[i]-'a';
	}
	char pattern[m];
	for (int i=0; i<m; i++) {
		pattern[i] = bi[i]-'a';
	}
	int next[m][26];
	for (int i=0; i<m; i++) {
		for (int j=0; j<26; j++) {
			next[i][j] = 0;
		}
	}
	int prev;
	for (int i=1; i<m; i++) {
		prev = next[i-1][pattern[i-1]];
		next[i-1][pattern[i-1]] = i;
		for (int j=0; j<26; j++) {
			next[i][j] = next[prev][j];
		}
	}
}