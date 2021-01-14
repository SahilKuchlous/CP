#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
ifstream fin("measurement.in");
ofstream fout("measurement.out");
map< long long, long long > prod;
set< pair<long long, long long>, greater< pair<long long, long long> > > ranking;
pair<long long, long long> pre;
int main () {
	int n, g;
	fin >> n >> g;
	vector< pair<long long, pair<long long, long long> > > qry;
	long long a, b, c;
	for (int i=0; i<n; i++) {
		fin >> a >> b >> c;
		qry.push_back(make_pair(a, make_pair(b, c)));
	}
	sort(qry.begin(), qry.end());
	pre = make_pair(g, 0);
	ranking.insert(pre);
	int o = 0;
	for (auto i: qry) {
		bool e = false;
		pair<long long, long long> det = i.second;
		if (prod.find(det.first) == prod.end()) {
			prod[det.first] = g+det.second;
			ranking.insert(make_pair(prod[det.first], det.first));
		} else {
			ranking.erase(make_pair(prod[det.first], det.first));
			if (prod[det.first] == pre.first && det.first != pre.second && det.second < 0) {
				e = true;
				o++;
			}
			prod[det.first] += det.second;
			ranking.insert(make_pair(prod[det.first], det.first));
		}
		pair<long long, long long> best = *ranking.begin();
		// cout << best.first << " " << best.second << " " << prod[det.first] << endl;
		if (best.second != pre.second || prod[det.first] == pre.first) {
			// cout << best.first << " " << best.second << endl;
			o++;
		}
		ranking.erase(best);
		pair<long long, long long> sec_best = *ranking.begin();
		ranking.insert(best);
		if (best.second == det.first && best.first == sec_best.first && !e) {
			o++;
		}
		pre = best;
	}
	fout << o << endl;
}