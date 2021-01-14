#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
using namespace std;
ifstream fin("closing.in");
ofstream fout("closing.out");
int key[200100];
bool inc[200100];
int cnt;
int check (int x) {
	key[x] = key[key[x]];
	if (key[x] != x) {
		return check(key[x]);
	}
	return x;
}
void merge (int x, int y) {
	key[check(x)] = check(y);
}
int main () {
	int n, m;
	fin >> n >> m;
	set<int> adj[n+1];
	int ai, bi;
	for (int i=0; i<m; i++) {
		fin >> ai >> bi;
		adj[ai].insert(bi);
		adj[bi].insert(ai);
	}
	int rem[n];
	for (int i=0; i<n; i++) {
		fin >> rem[i];
	}
	reverse(rem, rem+n);
	cnt = 0;
	int o[n];
	for (int i=1; i<=n; i++) {
		inc[i] = false;
	}
	for (int i=0; i<n; i++) {
		inc[rem[i]] = true;
		key[rem[i]] = rem[i];
		cnt++;
		for (auto j: adj[rem[i]]) {
			if (inc[j] && check(rem[i]) != check(j)) {
				merge(rem[i], j);
				cnt--;
			}
		}
		o[i] = cnt;
	}
	for (int i=n-1; i>=0; i--) {
		if (o[i] == 1) {
			fout << "YES" << endl;
		} else {
			fout << "NO" << endl;
		}
	}
}