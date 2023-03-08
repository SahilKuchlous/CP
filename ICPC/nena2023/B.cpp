#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main () {
	char order[4];
	order[0] = 'A';
	order[1] = 'T';
	order[2] = 'G';
	order[3] = 'C';
	string s;
	cin >> s;
	int n = s.size();
	int psum[n+1][4];
	psum[0][0] = psum[0][1] = psum[0][2] = psum[0][3] = 0;
	for (int i=1; i<=n; i++) {
		for (int j=0; j<4; j++) {
			psum[i][j] = psum[i-1][j];
			if (s[i-1] == order[j]) {
				psum[i][j]++;
			}
		}
	}

	int m;
	cin >> m;
	for (int i=0; i<m; i++) {
		int l, r;
		cin >> l >> r;
		vector< pair<int, int> > ord;
		for (int j=0; j<4; j++) {
			ord.push_back(make_pair(-(psum[r][j]-psum[l-1][j]), j));
		}
		sort(ord.begin(), ord.end());
		string o = "";
		for (auto i: ord) {
			o += order[i.second];
		}
		cout << o << endl;
	}
}