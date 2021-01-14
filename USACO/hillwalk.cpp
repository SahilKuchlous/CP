#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
ifstream fin("hillwalk.in");
ofstream fout("hillwalk.out");
struct line {
	int ind, sx, sy, ex, ey;
};
struct comp {
	bool operator() (const struct line& l1, const struct line& l2) const {
		if (l2.sx > l1.sx) {
			long long x1 = l1.ex-l1.sx;
			long long y1 = l1.ey-l1.sy;
			long long x2 = l2.sx-l1.sx;
			long long y2 = l2.sy-l1.sy;
			long long cp = x1*y2 - y1*x2;
			if (cp > 0) {
				return true;
			}
			return false;
		} else {
			long long x1 = l2.ex-l2.sx;
			long long y1 = l2.ey-l2.sy;
			long long x2 = l1.sx-l2.sx;
			long long y2 = l1.sy-l2.sy;
			long long cp = x1*y2 - y1*x2;
			if (cp < 0) {
				return true;
			}
			return false;
		}
	}
};
int main () {
	ios_base::sync_with_stdio(false);
	fin.tie(0);
	int n;
	fin >> n;
	vector<struct line> lines(n+1);
	set< pair<int, int> > ord;
	for (int i=1; i<n+1; i++) {
		lines[i].ind = i;
		fin >> lines[i].sx >> lines[i].sy >> lines[i].ex >> lines[i].ey;
		ord.insert(make_pair(lines[i].sx, -i));
		ord.insert(make_pair(lines[i].ex, i));
	}
	set<struct line, comp> s;
	int cur = 1;
	int next;
	int count = 1;
	for (auto i: ord) {
		if (i.second < 0) {
			s.insert(lines[-i.second]);
		} else {
			s.erase(lines[i.second]);
			if (i.second == cur) {
				set<struct line, comp>::iterator it = upper_bound(s.begin(), s.end(), lines[i.second], comp());
				if (it == s.begin()) {
					next = -1;
				} else {
					while (true) {
						it = prev(it);
						if (it->ex == lines[i.second].ex) {
							if (it == s.begin()) {
								s.erase(it);
								next = -1;
								break;
							}
							s.erase(it);
							continue;
						}
						next = it->ind;
						break;
					}
				}
				if (next == -1) {
					break;
				} else {
					cur = next;
					count++;
				}
			}
		}
	}
	fout << count << endl;
}