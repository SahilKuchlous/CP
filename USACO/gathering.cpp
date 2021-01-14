#include <iostream>
#include <fstream>
#include <vector>
#include <set>
using namespace std;
ifstream fin("gathering.in");
ofstream fout("gathering.out");
int n, m;
vector<int> adj[100100];
vector<int> lim_out[100100];
int adj_cnt[100100];
int lim_cnt[100100];
vector<int> cur;
bool done[100100];
bool o[100100];
bool pos = true;
int root;
void dfs (int x, int p) {
	o[x] = true;
	for (auto i: adj[x]) {
		if (i != p && lim_out[i].size() == 0) {
			dfs(i, x);
		}
	}
}
int main () {
	fin >> n >> m;
	int ai, bi;
	for (int i=0; i<n-1; i++) {
		fin >> ai >> bi;
		ai--;
		bi--;
		adj[ai].push_back(bi);
		adj[bi].push_back(ai);
		adj_cnt[ai]++;
		adj_cnt[bi]++;
	}
	for (int i=0; i<m; i++) {
		fin >> ai >> bi;
		ai--;
		bi--;
		lim_out[ai].push_back(bi);
		lim_cnt[bi]++;
	}
	for (int i=0; i<n; i++) {
		if (adj_cnt[i] <= 1 && lim_cnt[i] <= 0) {
			cur.push_back(i);
			done[i] = true;
		}
	}
	for (int i=0; i<n-1; i++) {
		if (i >= cur.size()) {
			pos = false;
			break;
		}
		for (auto j: lim_out[cur[i]]) {
			lim_cnt[j]--;
			if (adj_cnt[j] <= 1 && lim_cnt[j] <= 0 && !done[j]) {
				cur.push_back(j);
				done[j] = true;
			}
		}
		for (auto j: adj[cur[i]]) {
			adj_cnt[j]--;
			if (adj_cnt[j] <= 1 && lim_cnt[j] <= 0 && !done[j]) {
				cur.push_back(j);
				done[j] = true;
			}
		}
	}
	if (cur.size() < n) {
		pos = false;
	} else {
		root = cur[n-1];
	}
	if (pos) {
		dfs(root, 0);
	}
	for (int i=0; i<n; i++) {
		fout << o[i] << endl;
	}
}