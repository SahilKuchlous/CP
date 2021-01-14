#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
ifstream fin("gangs.in");
ofstream fout("gangs.out");
int n, m;
vector<int> cur_cows(100);
int cur_type, cur_cnt;
int goal;
void update (int type) {
	if (cur_cnt == 0) {
		cur_type = type;
	}
	if (type == cur_type) {
		cur_cnt++;
	} else {
		cur_cnt--;
	}
}
int calc () {
	int org_type = cur_type;
	int org_cnt = cur_cnt;
	vector<int> cows = cur_cows;
	sort(cows.begin()+1, cows.end());
	while (cows.back() > 0) {
		for (int i=cows.size()-1; i>0; i--) {
			cows[i]--;
			update(i);
			if (cows[i-1] <= cows[i]) {
				break;
			}
		}
	}
	for (int i=0; i<cows[0]; i++) {
		update(0);
	}
	int new_cnt = cur_cnt;
	int new_type = cur_type;
	cur_cnt = org_cnt;
	cur_type = org_type;
	if (new_type == 0) {
		return new_cnt;
	} else {
		return 0;
	}
}
int main () {
	fin >> n >> m;
	for (int i=0; i<m; i++) {
		fin >> cur_cows[i];
	}
	cur_type = cur_cnt = 0;
	goal = calc();
	cur_type = cur_cnt = 0;
	if (goal > 0) {
		fout << "YES" << endl;
		fout << goal << endl;
		for (int i=0; i<n; i++) {
			int prev_type = cur_type;
			int prev_cnt = cur_cnt;
			for (int j=0; j<m; j++) {
				cur_cows[j]--;
				update(j);
				if (calc() == goal) {
					fout << j+1 << endl;
					break;
				} else {
					cur_type = prev_type;
					cur_cnt = prev_cnt;
					cur_cows[j]++;
				}
			}
		}
	} else {
		fout << "NO" << endl;
	}
}