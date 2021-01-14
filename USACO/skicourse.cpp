#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("skicourse.in");
ofstream fout("skicourse.out");
int main () {
	int n, m;
	fin >> n >> m;
	char grid[n][m];
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			fin >> grid[i][j];
		}
	}
	int o = min(n, m);
	char type;
	int len, maxlen;
	for (int i=0; i<n; i++) {
		maxlen = 0;
		len = 0;
		type = 'a';
		for (int j=0; j<m; j++) {
			if (grid[i][j] == type) {
				len++;
			} else {
				type = grid[i][j];
				len = 1;
			}
			maxlen = max(len, maxlen);
		}
		o = min(o, maxlen);
	}
	for (int j=0; j<m; j++) {
		maxlen = 0;
		len = 0;
		type = 'a';
		for (int i=0; i<n; i++) {
			if (grid[i][j] == type) {
				len++;
			} else {
				type = grid[i][j];
				len = 1;
			}
			maxlen = max(len, maxlen);
		}
		o = min(o, maxlen);
	}
	fout << o << endl;
}