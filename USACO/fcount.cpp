#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream fin("fcount.in");
ofstream fout("fcount.out");
int n;
int a[600];
vector<int> cur;
vector<int> nxt;
bool check () {
	sort(cur.begin(), cur.end());
	nxt.clear();
	for (int i=cur.size()-2; i>=0; i--) {
		if (cur[cur.size()-1] > 0 && cur[i] > 0) {
			cur[cur.size()-1]--;
			cur[i]--;
		}
		if (cur[i] != 0) nxt.push_back(cur[i]);
	}
	if (cur[cur.size()-1] != 0) {
		return false;
	}
	if (nxt.size() == 0) {
		return true;
	}
	cur = nxt;
	return check();
}
int main () {
	fin >> n;
	for (int i=0; i<n+1; i++) {
		fin >> a[i];
	}
	vector<int> o;
	for (int i=0; i<n+1; i++) {
		cur.clear();
		for (int j=0; j<n+1; j++) {
			if (j != i) cur.push_back(a[j]);
		}
		if (check()) {
			o.push_back(i);
		}
	}
	fout << o.size() << endl;
	for (auto i: o) {
		fout << i+1 << endl;
	}
}