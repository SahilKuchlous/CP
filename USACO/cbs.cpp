#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
ifstream fin("cbs.in");
ofstream fout("cbs.out");
int main () {
	ios_base::sync_with_stdio(false);
	fin.tie(0);
	int k, n;
	fin >> k >> n;
	string inp;
	int seq[k][n];
	for (int i=0; i<k; i++) {
		fin >> inp;
		for (int j=0; j<n; j++) {
			if (inp.at(j) == '(') {
				seq[i][j] = 1;
			} else {
				seq[i][j] = -1;
			}
		}
	}
	int pre[k][n];
	map<int, int> pos[k];
	for (int i=0; i<k; i++) {
		pre[i][0] = seq[i][0];
		pos[i][pre[i][0]] = 0;
	}
	long long o = 0;
	for (int i=1; i<n; i++) {
		int m = 0;
		for (int j=0; j<k; j++) {
			pre[j][i] = pre[j][i-1]+seq[j][i];
			pos[j][pre[j][i]] = i;
			m = max(m, pos[j][pre[j][i]-1]);
		}
		for (int j=m; j<i; j++) {
			bool p = true;
			for (int x=0; x<k; x++) {
				if (pre[x][i] != pre[x][j]) {
					p = false;
					break;
				}
			}
			if (p) o++;
		}
	}
	fout << o << endl;
}