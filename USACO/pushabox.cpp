#include <iostream>
#include <fstream>
#include <set>
#include <vector>
using namespace std;
#define NMAX 1500
ifstream fin("pushabox.in");
ofstream fout("pushabox.out");
char grid[NMAX*NMAX];
int cow_pos, box_pos;
vector<int> adj1[NMAX*NMAX];
vector< pair<int, int> > bcc_edges[NMAX*NMAX];
int bcc_cnt = 0;
int disc[NMAX*NMAX];
int low[NMAX*NMAX];
int ind = 0;
vector< pair<int, int> > cur;
set<int> bcc[NMAX*NMAX];
vector<int> adj[4*NMAX*NMAX];
bool vis[4*NMAX*NMAX];
bool out[NMAX*NMAX];
int org_ori = -1;
void dfs1 (int x, int p) {
	disc[x] = low[x] = ind;
	ind++;
	int child = 0;
	if (x == box_pos) {
		if (x-p == NMAX) {
			org_ori = 0;
		} else if (x-p == -1) {
			org_ori = 1;
		} else if (x-p == -NMAX) {
			org_ori = 2;
		} else if (x-p == 1) {
			org_ori = 3;
		}
	}
	for (auto i: adj1[x]) {
		if (disc[i] == -1) {
			child++;
			cur.push_back(make_pair(x, i));
			dfs1(i, x);
			low[x] = min(low[x], low[i]);
			if (p == -1 && child > 1) {
				while (cur.back() != make_pair(x, i)) {
					bcc_edges[bcc_cnt].push_back(cur.back());
					cur.pop_back();
				}
				bcc_edges[bcc_cnt].push_back(cur.back());
				cur.pop_back();
				bcc_cnt++;
			}
			if (low[i] >= disc[x]) {
				while (cur.back() != make_pair(x, i)) {
					bcc_edges[bcc_cnt].push_back(cur.back());
					cur.pop_back();
				}
				bcc_edges[bcc_cnt].push_back(cur.back());
				cur.pop_back();
				bcc_cnt++;
			}
		} else if (i != p && disc[i] < low[x]) {
			cur.push_back(make_pair(x, i));
		}
	}
}
void dfs2 (int x) {
	vis[x] = true;
	out[x%(NMAX*NMAX)] = true;
	for (auto i: adj[x]) {
		if (!vis[i]) {
			dfs2(i);
		}
	}
}
int main () {
	int n, m, q;
	fin >> n >> m >> q;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			fin >> grid[i*NMAX+j];
			if (grid[i*NMAX+j] == 'A') cow_pos = i*NMAX+j;
			if (grid[i*NMAX+j] == 'B') box_pos = i*NMAX+j;
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (grid[i*NMAX+j] == '#') continue;
			if (i > 0 && grid[(i-1)*NMAX+j] != '#') adj1[i*NMAX+j].push_back((i-1)*NMAX+j);
			if (i < n-1 && grid[(i+1)*NMAX+j] != '#') adj1[i*NMAX+j].push_back((i+1)*NMAX+j);
			if (j > 0 && grid[i*NMAX+j-1] != '#') adj1[i*NMAX+j].push_back(i*NMAX+j-1);
			if (j < m-1 && grid[i*NMAX+j+1] != '#') adj1[i*NMAX+j].push_back(i*NMAX+j+1);
		}
	}
	for (int i=0; i<NMAX*NMAX; i++) {
		disc[i] = -1;
	}
	dfs1(cow_pos, -1);
	while (cur.size() > 0) {
		bcc_edges[bcc_cnt].push_back(cur.back());
		cur.pop_back();
	}
	for (int i=0; i<bcc_cnt; i++) {
		for (auto j: bcc_edges[i]) {
			bcc[j.first].insert(i);
			bcc[j.second].insert(i);
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (disc[i*NMAX+j] == -1) continue;
			if (i > 0 && grid[(i-1)*NMAX+j] != '#') {
				if (i < n-1 && grid[(i+1)*NMAX+j] != '#') adj[i*NMAX+j].push_back((i+1)*NMAX+j);
				if (j < m-1 && grid[i*NMAX+j+1] != '#') {
					for (auto k: bcc[(i-1)*NMAX+j]) {
						if (bcc[i*NMAX+j+1].find(k) != bcc[i*NMAX+j+1].end()) {
							adj[i*NMAX+j].push_back(NMAX*NMAX+i*NMAX+j);
							adj[NMAX*NMAX+i*NMAX+j].push_back(i*NMAX+j);
						}
					}
				}
				if (i < n-1 && grid[(i+1)*NMAX+j] != '#') {
					for (auto k: bcc[(i-1)*NMAX+j]) {
						if (bcc[(i+1)*NMAX+j].find(k) != bcc[(i+1)*NMAX+j].end()) {
							adj[i*NMAX+j].push_back(2*NMAX*NMAX+i*NMAX+j);
							adj[2*NMAX*NMAX+i*NMAX+j].push_back(i*NMAX+j);
						}
					}
				}
				if (j > 0 && grid[i*NMAX+j-1] != '#') {
					for (auto k: bcc[(i-1)*NMAX+j]) {
						if (bcc[i*NMAX+j-1].find(k) != bcc[i*NMAX+j-1].end()) {
							adj[i*NMAX+j].push_back(3*NMAX*NMAX+i*NMAX+j);
							adj[3*NMAX*NMAX+i*NMAX+j].push_back(i*NMAX+j);
						}
					}
				}
			}
			if (j < m-1 && grid[i*NMAX+j+1] != '#') {
				if (j > 0 && grid[i*NMAX+j-1] != '#') adj[NMAX*NMAX+i*NMAX+j].push_back(NMAX*NMAX+i*NMAX+j-1);
				if (i < n-1 && grid[(i+1)*NMAX+j] != '#') {
					for (auto k: bcc[i*NMAX+j+1]) {
						if (bcc[(i+1)*NMAX+j].find(k) != bcc[(i+1)*NMAX+j].end()) {
							adj[NMAX*NMAX+i*NMAX+j].push_back(2*NMAX*NMAX+i*NMAX+j);
							adj[2*NMAX*NMAX+i*NMAX+j].push_back(NMAX*NMAX+i*NMAX+j);
						}
					}
				}
				if (j > 0 && grid[i*NMAX+j-1] != '#') {
					for (auto k: bcc[i*NMAX+j+1]) {
						if (bcc[i*NMAX+j-1].find(k) != bcc[i*NMAX+j-1].end()) {
							adj[NMAX*NMAX+i*NMAX+j].push_back(3*NMAX*NMAX+i*NMAX+j);
							adj[3*NMAX*NMAX+i*NMAX+j].push_back(NMAX*NMAX+i*NMAX+j);
						}
					}
				}
			}
			if (i < n-1 && grid[(i+1)*NMAX+j] != '#') {
				if (i > 0 && grid[(i-1)*NMAX+j] != '#') adj[2*NMAX*NMAX+i*NMAX+j].push_back(2*NMAX*NMAX+(i-1)*NMAX+j);
				if (j > 0 && grid[i*NMAX+j-1] != '#') {
					for (auto k: bcc[(i+1)*NMAX+j]) {
						if (bcc[i*NMAX+j-1].find(k) != bcc[i*NMAX+j-1].end()) {
							adj[2*NMAX*NMAX+i*NMAX+j].push_back(3*NMAX*NMAX+i*NMAX+j);
							adj[3*NMAX*NMAX+i*NMAX+j].push_back(2*NMAX*NMAX+i*NMAX+j);
						}
					}
				}
			}
			if (j > 0 && grid[i*NMAX+j-1] != '#') {
				if (j < m-1 && grid[i*NMAX+j+1] != '#') adj[3*NMAX*NMAX+i*NMAX+j].push_back(3*NMAX*NMAX+i*NMAX+j+1);
			}
		}
	}
	if (org_ori == 0) dfs2(box_pos);
	if (org_ori == 1) dfs2(NMAX*NMAX+box_pos);
	if (org_ori == 2) dfs2(2*NMAX*NMAX+box_pos);
	if (org_ori == 3) dfs2(3*NMAX*NMAX+box_pos);
	/*
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (out[i*NMAX+j]) {
				cout << i << " " << j << endl;
			} else {
				cout << "N" << endl;
			}
		}
	}
	return 0;
	*/
	int ai, bi;
	for (int i=0; i<q; i++) {
		fin >> ai >> bi;
		ai--;
		bi--;
		if (out[ai*NMAX+bi]) {
			fout << "YES" << endl;
		} else {
			fout << "NO" << endl;
		}
	}
}