#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <time.h>
using namespace std;
void dfs (pair<int, int> f, map< pair<int, int>, bool >& visited, vector< set< pair<int, int> > >& patch, int ind, map< pair<int, int>, set< pair<int, int> > >& nb, int dep) {
	// cout << f.first << " " << f.second << " " << dep << endl;
	dep++;
	visited[f] = true;
	patch[ind].insert(f);
	for (auto i : nb[f]) {
		if (!visited[i]) {
			dfs (i, visited, patch, ind, nb, dep);
		}
	}
}
int main () {
	clock_t tStart = clock();
	int r, c, n, x, y;
	cin >> r >> c >> n;
	set< pair<int, int> > f;
	for (int i=0; i<n; i++) {
		cin >> x >> y;
		f.insert(make_pair(x, y));
	}
	map< pair<int, int>, set< pair<int, int> > > nb;
	for (auto i : f) {
		if (f.find(make_pair(i.first+1, i.second)) != f.end()) {
			nb[i].insert(make_pair(i.first+1, i.second));
		}
		if (f.find(make_pair(i.first-1, i.second)) != f.end()) {
			nb[i].insert(make_pair(i.first-1, i.second));
		}
		if (f.find(make_pair(i.first, i.second+1)) != f.end()) {
			nb[i].insert(make_pair(i.first, i.second+1));
		}
		if (f.find(make_pair(i.first, i.second-1)) != f.end()) {
			nb[i].insert(make_pair(i.first, i.second-1));
		}
	}
	// cout << (double)(clock() - tStart)/CLOCKS_PER_SEC << endl;
	vector< set< pair<int, int> > > patch;
	map< pair<int, int>, bool > visited;
	int ind = 0;
	for (auto i : f) {
		visited[i] = false;
	}
	// cout << "E" << endl;
	for (auto i : f) {
		if (!visited[i]) {
			set< pair<int, int> > z;
			patch.push_back(z);
			dfs (i, visited, patch, ind, nb, 0);
			ind++;
		}
	}
	// cout << (double)(clock() - tStart)/CLOCKS_PER_SEC << endl;
	int max_s = 0, score;
	for (auto i : patch) {
		score = 0;
		for (auto j : i) {
			score += 4-nb[j].size();
		}
		if (score > max_s) {
			max_s = score;
		}
	}
	// cout << (double)(clock() - tStart)/CLOCKS_PER_SEC << endl;
	cout << max_s << endl;
	return 0;
}