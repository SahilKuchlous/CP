#include <iostream>
#include <fstream>
#include <set>
using namespace std;
ifstream fin("boards.in");
ofstream fout("boards.out");
int main () {
	int n, p;
	fin >> n >> p;
	pair<long long, long long> points[2*p+2];
	points[0] = make_pair(0, 0);
	points[1] = make_pair(n, n);
	long long dist[2*p+2][2*p+2];
	for (int i=0; i<2*p+2; i++) {
		for (int j=0; j<2*p+2; j++) {
			dist[i][j] = 1e11;
		}
	}
	pair<int, int> start;
	pair<int, int> end;
	for (int i=0; i<p; i++) {
		fin >> start.first >> start.second >> end.first >> end.second;
		points[2*i+2] = start;
		points[2*i+3] = end;
		dist[2*i+2][2*i+3] = 0;
	}
	for (int i=0; i<2*p+2; i++) {
		for (int j=0; j<2*p+2; j++) {
			if (i != j && points[i].first <= points[j].first && points[i].second <= points[j].second) {
				dist[i][j] = min(dist[i][j], points[j].first-points[i].first+points[j].second-points[i].second);
			}
		}
	}
	long long min_dist;
	int min_i;
	set<int> vis;
	while (true) {
		min_dist = 1e12;
		min_i = -1;
		for (int i=1; i<2*p+2; i++) {
			if (vis.find(i) == vis.end() && dist[0][i] < min_dist) {
				min_dist = dist[0][i];
				min_i = i;
			}
		}
		vis.insert(min_i);
		if (min_i == 1) {
			break;
		}
		for (int i=1; i<2*p+2; i++) {
			dist[0][i] = min(dist[0][i], dist[0][min_i]+dist[min_i][i]);
		}
	}
	fout << dist[0][1] << endl;
}