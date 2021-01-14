#include <iostream>
#include <fstream>
#include <set>
#include <vector>
using namespace std;
ifstream fin("shuffle.in");
ofstream fout("shuffle.out");
set<int> vis;
vector<int> path;
set<int> loc;
bool done = false;
int a[100100];
int len;
void dfs(int cur) {
	if (loc.find(cur) != loc.end()) {
		done = true;
		for (int i=0; i<path.size(); i++) {
			if (path[i] == cur) {
				len = path.size()-i;
				break;
			}
		}
		return;
	}
	if (vis.find(cur) != vis.end()) {
		return;
	}
	path.push_back(cur);
	loc.insert(cur);
	vis.insert(cur);
	dfs(a[cur]);
}
int main () {
	int n;
	fin >> n;
	for (int i=1; i<=n; i++) {
		fin >> a[i];
	}
	int c = 1;
	int o = 0;
	while (vis.size() < n) {
		for (int i=c; i<=n; i++) {
			if (vis.find(i) == vis.end()) {
				done = false;
				vis.insert(i);
				path.clear();
				path.push_back(i);
				loc.clear();
				loc.insert(i);
				dfs(a[i]);
				c = i+1;
				if (done) {
					o += len;
				}
				break;
			}
		}
	}
	fout << o << endl;
}