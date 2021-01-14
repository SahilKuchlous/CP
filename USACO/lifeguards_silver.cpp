#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
using namespace std;
ifstream fin("lifeguards.in");
ofstream fout("lifeguards.out");
int main () {
	int n;
	fin >> n;
	pair<int, int> rng[n];
	pair<int, int> rng_fwd[n];
	pair<int, int> rng_bwd[n];
	map< pair<int, int>, int> ind;
	for (int i=0; i<n; i++) {
		fin >> rng[i].first >> rng[i].second;
		rng[i].second--;
		ind[rng[i]] = i;
		rng_fwd[i] = rng[i];
		rng_bwd[i] = make_pair(rng[i].second, rng[i].first);
	}
	sort(rng_fwd, rng_fwd+n);
	int fwd[n];
	int m = 0;
	for (auto i: rng_fwd) {
		fwd[ind[i]] = max(i.first, m+1);
		m = max(i.second, m);
	}
	sort( rng_bwd, rng_bwd+n, greater< pair<int, int> >() );
	int bwd[n];
	m = 1e9;
	for (auto i: rng_bwd) {
		bwd[ind[make_pair(i.second, i.first)]] = min(i.first, m-1);
		m = min(i.second, m);
	}
	int ign = -1;
	int best = 1e9;
	for (int i=0; i<n; i++) {
		int score = max(0, bwd[i]-fwd[i]+1);
		// cout << score << endl;
		if (score < best) {
			best = score;
			ign = i;
		}
	}
	// cout << ign << endl;
	int end_i = 0;
	int o = 0;
	for (int i=0; i<n; i++) {
		// cout << ind[rng_fwd[i]] << ign << endl;
		if (ind[rng_fwd[i]] != ign) {
			if (rng_fwd[i].first <= end_i) {
				o += max(0, rng_fwd[i].second-end_i);
			} else {
				o += max(0, rng_fwd[i].second-rng_fwd[i].first+1);
			}
			end_i = max(rng_fwd[i].second, end_i);
		}
	}
	fout << o << endl;
}