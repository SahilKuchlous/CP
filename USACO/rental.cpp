#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;
ifstream fin("rental.in");
ofstream fout("rental.out");
int n, m, r;
long long c[100100];
pair<int, int> s[100100];
int v[100100];
int vi = 0;
int sred = 0;
long long shift = 0;
int si = 0;
long long o = 0;
vector< pair<long long, long long> > presum;
int main () {
	fin >> n >> m >> r;
	for (int i=0; i<n; i++) {
		fin >> c[i];
	}
	sort(c, c+n, greater<int>());
	for (int i=0; i<m; i++) {
		fin >> s[i].second >> s[i].first;
	}
	sort(s, s+m, greater< pair<int, int> >());
	for (int i=0; i<r; i++) {
		fin >> v[i];
	}
	sort(v, v+r, greater<int>());
	presum.push_back(make_pair(s[0].second, s[0].first*s[0].second));
	for (int i=1; i<m; i++) {
		presum.push_back(make_pair(0, 0));
		presum[i].first = presum[i-1].first+s[i].second;
		presum[i].second = presum[i-1].second+(s[i].first*s[i].second);
	}
	int total, rem;
	int fnt = 0, bk = n-1;
	while (fnt <= bk) {
		total = 0;
		vector< pair<long long, long long> >::iterator it = upper_bound(presum.begin(), presum.end(), make_pair(c[fnt]+shift, (long long)1e12));
		if (it == presum.begin()+si) {
			total = s[it-presum.begin()].first*c[fnt];
		} else {
			total = presum[it-presum.begin()-1].second-sred;
			total += s[it-presum.begin()].first*(c[fnt]+shift-presum[it-presum.begin()-1].first);
		}
		// cout << fnt << " " << total << endl;
		if (total > v[vi]) {
			o += total;
			shift += c[fnt];
			sred += total;
			si = it-presum.begin();
			fnt++;
		} else {
			o += v[vi];
			vi++;
			bk--;
		}
	}
	fout << o << endl;
}