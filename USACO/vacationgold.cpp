#include <iostream>
#include <fstream>
#include <map>
#include <vector>
using namespace std;
ifstream fin("vacationgold.in");
ofstream fout("vacationgold.out");
int main () {
	int n, m, k, q;
	fin >> n >> m >> k >> q;
	vector< pair<int, int> > out[n];
	int ai, bi, ci;
	for (int i=0; i<m; i++) {
		fin >> ai >> bi >> ci;
		ai--;
		bi--;
		out[ai].push_back(make_pair(bi, ci));
	}
	int hub[n];
	for (int i=0; i<n; i++) {
		hub[i] = -1;
	}
	int pos[k];
	for (int i=0; i<k; i++) {
		fin >> ai;
		ai--;
		hub[ai] = i;
		pos[i] = ai;
		out[ai].push_back(make_pair(ai, 0));
	}
	long long hub_dist[k][k];
	for (int i=0; i<k; i++) {
		for (int j=0; j<k; j++) {
			hub_dist[i][j] = 1e14;
		}
	}
	for (int i=0; i<n; i++) {
		if (hub[i] > -1) {
			for (auto j: out[i]) {
				if (hub[j.first] > -1) {
					hub_dist[hub[i]][hub[j.first]] = min(hub_dist[hub[i]][hub[j.first]], (long long)j.second);
				} else {
					for (auto k: out[j.first]) {
						if (hub[k.first] > -1) {
							hub_dist[hub[i]][hub[k.first]] = min(hub_dist[hub[i]][hub[k.first]], (long long)j.second+k.second);
						}
					}
				}
			}
		}
	}
	for (int m=0; m<k; m++) {
		for (int i=0; i<k; i++) {
			for (int j=0; j<k; j++) {
				if (hub_dist[i][m] < 1e14 && hub_dist[m][j] < 1e14) hub_dist[i][j] = min(hub_dist[i][j], hub_dist[i][m]+hub_dist[m][j]);
			}
		}
	}
	vector< pair<int, int> > inc[n];
	for (int i=0; i<n; i++) {
		if (hub[i] > -1) {
			inc[i].push_back(make_pair(i, 0));
			for (auto j: out[i]) {
				if (hub[j.first] == -1) inc[j.first].push_back(make_pair(i, j.second));
			}
			out[i].clear();
			out[i].push_back(make_pair(i, 0));
		}
	}
	long long dist_inc[n][k];
	long long dist_out[n][k];
	for (int i=0; i<n; i++) {
		for (int j=0; j<k; j++) {
			dist_inc[i][j] = dist_out[i][j] = 1e14;
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<k; j++) {
			for (auto a: out[i]) {
				dist_out[i][j] = min(dist_out[i][j], a.second+hub_dist[hub[a.first]][j]);
			}
			for (auto a: inc[i]) {
				dist_inc[i][j] = min(dist_inc[i][j], hub_dist[j][hub[a.first]]+a.second);
			}
		}
	}
	long long cnt = 0;
	long long total = 0;
	long long cur;
	for (int i=0; i<q; i++) {
		fin >> ai >> bi;
		ai--;
		bi--;
		cur = 1e14;
		for (int j=0; j<k; j++) {
			if (dist_out[ai][j] < 1e14 && dist_inc[bi][j] < 1e14) cur = min(cur, dist_out[ai][j]+dist_inc[bi][j]);
		}
		if (cur < 1e14) {
			cnt++;
			total += cur;
		}
	}
	fout << cnt << endl;
	fout << total << endl;
}