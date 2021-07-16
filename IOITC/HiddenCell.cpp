#include <vector>
#include <iostream>
#include <string>
using namespace std;

bool doesPathExist (const vector<string>& M);

int n;

bool check_col (int x) {
	vector<string> grid;
	for (int i=0; i<n; i++) {
		string cur = "";
		for (int j=0; j<n; j++) {
			if (j == x) {
				cur += '0';
			} else {
				cur += '1';
			}
		}
		grid.push_back(cur);
	}
	return doesPathExist(grid);
}

int find_row () {
	int st = 1, dist = 1;
	vector<string> grid;
	while (st+dist+1 < n-1) {
		bool left = false;
		grid.clear();
		string cur = "";
		for (int i=0; i<st; i++) {
			cur = "";
			for (int j=0; j<n; j++) {
				cur += '1';
			}
			grid.push_back(cur);
		}
		int pos = st;
		while (pos < n-1) {
			cur = "10";
			for (int i=2; i<n-2; i++) {
				cur += '0';
			}
			if (pos != st) {
				cur += "01";
			} else {
				cur += "00";
			}
			grid.push_back(cur);
			left = !left;
			for (int i=pos+1; i<min(n-1, pos+dist+1); i++) {
				cur = "";
				for (int j=0; j<n; j++) {
					if ((left && j == 1) || (!left && j == n-2)) {
						cur += '0';
					} else {
						cur += '1';
					}
				}
				grid.push_back(cur);
			}
			pos += dist+1;
		}
		cur = "";
		for (int j=0; j<n; j++) {
			if ((left && j == 1) || (!left && j == n-2)) {
				cur += '0';
			} else {
				cur += '1';
			}
		}
		grid.push_back(cur);
		bool ans = doesPathExist(grid);
		cout << st << " " << dist << " " << ans << endl;
		for (auto i: grid) {
			cout << i << endl;
		}
		cout << endl;
		if (!ans) {
			st = st+dist/2+1;
		}
		dist = dist*2+1;
	}
	return st;
}

pair<int, int> findHiddenCell (int n_in) {
	n = n_in;
	int row = -1, col = -1;
	if (check_col(1)) {
		row = 1;
	} else if (check_col(n-2)) {
		row = n-2;
	} else {
		row = find_row();
	}
	int l = 1, r = n-1, m;
	while (l < r) {
		m = (l+r)/2;
		vector<string> grid;
		string cur = "";
		for (int i=0; i<n; i++) {
			cur += '1';
		}
		grid.push_back(cur);
		for (int i=1; i<n-1; i++) {
			cur = "";
			if (i == row) {
				for (int j=0; j<n; j++) {
					cur += '0';
				}
				grid.push_back(cur);
				continue;
			}
			for (int j=0; j<n; j++) {
				if (l <= j && j <= m) {
					cur += '1';
				} else {
					cur += '0';
				}
			}
			grid.push_back(cur);
		}
		cur = "";
		for (int i=0; i<n; i++) {
			cur += '1';
		}
		grid.push_back(cur);
		bool ans = doesPathExist(grid);
		if (ans) {
			r = m;
		} else {
			l = m+1;
		}
	}
	return make_pair(row, l);
}

/*
pair<int, int> findHiddenCell (int n) {
	int row = -1, col = -1;
	for (int i=1; i<n-1; i++) {
		vector<string> grid;
		string cur = "";
		for (int k=0; k<n; k++) {
			cur += '1';
		}
		grid.push_back(cur);
		for (int j=1; j<n-1; j++) {
			cur = "";
			for (int k=0; k<n; k++) {
				if (j == i) {
					cur += '0';
					continue;
				}
				cur += '1';
			}
			grid.push_back(cur);
		}
		cur = "";
		for (int k=0; k<n; k++) {
			cur += '1';
		}
		grid.push_back(cur);
		bool ans = doesPathExist(grid);
		if (ans) {
			row = i;
			break;
		}
	}
	int l = 1, r = n-1, m;
	while (l < r) {
		m = (l+r)/2;
		vector<string> grid;
		string cur = "";
		for (int i=0; i<n; i++) {
			cur += '1';
		}
		grid.push_back(cur);
		for (int i=1; i<n-1; i++) {
			cur = "";
			if (i == row) {
				for (int j=0; j<n; j++) {
					cur += '0';
				}
				grid.push_back(cur);
				continue;
			}
			for (int j=0; j<n; j++) {
				if (l <= j && j <= m) {
					cur += '1';
				} else {
					cur += '0';
				}
			}
			grid.push_back(cur);
		}
		cur = "";
		for (int i=0; i<n; i++) {
			cur += '1';
		}
		grid.push_back(cur);
		bool ans = doesPathExist(grid);
		if (ans) {
			r = m;
		} else {
			l = m+1;
		}
	}
	return make_pair(row, l);
}
*/

/*
pair<int, int> findHiddenCell (int n) {
	int row = -1, col = -1;
	for (int i=1; i<n-1; i++) {
		vector<string> grid;
		string cur = "";
		for (int k=0; k<n; k++) {
			cur += '1';
		}
		grid.push_back(cur);
		for (int j=1; j<n-1; j++) {
			cur = "";
			for (int k=0; k<n; k++) {
				if (j == i) {
					cur += '0';
					continue;
				}
				cur += '1';
			}
			grid.push_back(cur);
		}
		cur = "";
		for (int k=0; k<n; k++) {
			cur += '1';
		}
		grid.push_back(cur);
		bool ans = doesPathExist(grid);
		if (ans) {
			row = i;
			break;
		}
	}
	for (int i=1; i<n-1; i++) {
		vector<string> grid;
		for (int j=0; j<n; j++) {
			string cur = "1";
			for (int k=1; k<n-1; k++) {
				if (k == i) {
					cur += '0';
					continue;
				}
				cur += '1';
			}
			cur += '1';
			grid.push_back(cur);
		}
		bool ans = doesPathExist(grid);
		if (ans) {
			col = i;
			break;
		}
	}
	return make_pair(row, col);
}
*/

/*
3
50
25 25
50
13 46
50
28 16
*/