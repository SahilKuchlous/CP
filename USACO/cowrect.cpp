#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream fin("cowrect.in");
ofstream fout("cowrect.out");
pair<int, int> presum[1100][1100];
pair<int, int> total (int x1, int y1, int x2, int y2) {
	return make_pair(presum[x2][y2].first-presum[x1][y2].first-presum[x2][y1].first+presum[x1][y1].first, presum[x2][y2].second-presum[x1][y2].second-presum[x2][y1].second+presum[x1][y1].second);
}
int main () {
	int n;
	fin >> n;
	char grid[1100][1100];
	for (int i=0; i<=1010; i++) {
		for (int j=0; j<=1010; j++) {
			grid[i][j] = '.';
		}
	}
	int xi, yi;
	char ti;
	for (int i=0; i<n; i++) {
		fin >> xi >> yi >> ti;
		xi++;
		yi++;
		grid[xi][yi] = ti;
	}
	vector<int> pos_x, pos_y;
	for (int i=0; i<=1010; i++) {
		for (int j=0; j<=1010; j++) {
			presum[i][j] = make_pair(0, 0);
			if (grid[i][j] == 'H') {
				presum[i][j].first = 1;
				pos_x.push_back(i);
				pos_y.push_back(j);
			} else if (grid[i][j] == 'G') {
				presum[i][j].second = 1;
			}
			if (i > 0) {
				presum[i][j].first += presum[i-1][j].first;
				presum[i][j].second += presum[i-1][j].second;
			}
			if (j > 0) {
				presum[i][j].first += presum[i][j-1].first;
				presum[i][j].second += presum[i][j-1].second;
			}
			if (i > 0 && j > 0) {
				presum[i][j].first -= presum[i-1][j-1].first;
				presum[i][j].second -= presum[i-1][j-1].second;
			}
		}
	}
	sort(pos_x.begin(), pos_x.end());
	pos_x.resize(unique(pos_x.begin(), pos_x.end()) - pos_x.begin());
	sort(pos_y.begin(), pos_y.end());
	pos_y.resize(unique(pos_y.begin(), pos_y.end()) - pos_y.begin());
	int o1 = 0, o2 = 0;
	for (int i=0; i<pos_x.size(); i++) {
		for (int j=i; j<pos_x.size(); j++) {
			int prev = -1;
			for (int k=0; k<pos_y.size(); k++) {
				if (total(pos_x[i]-1, pos_y[k]-1, pos_x[j], pos_y[k]).first == 0) {
					continue;
				}
				if (prev == -1) prev = k;
				if (total(pos_x[i]-1, pos_y[k]-1, pos_x[j], pos_y[k]).second > 0) {
					prev = k+1;
					continue;
				}
				if (total(pos_x[i]-1, pos_y[prev]-1, pos_x[j], pos_y[k]).second > 0) {
					prev = k;
				}
				int cnt = total(pos_x[i]-1, pos_y[prev]-1, pos_x[j], pos_y[k]).first;
				if (cnt > o1) {
					o1 = cnt;
					o2 = (pos_x[j]-pos_x[i])*(pos_y[k]-pos_y[prev]);
				} else if (cnt == o1) {
					o2 = min(o2, (pos_x[j]-pos_x[i])*(pos_y[k]-pos_y[prev]));
				}
			}
		}
	}
	fout << o1 << endl << o2 << endl;
}