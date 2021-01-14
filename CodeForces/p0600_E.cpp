#include <iostream>
#include <vector>
#include <map>
using namespace std;
int n;
int color[100100];
vector<int> adj[100100];
int ptr[100100];
map<int, int> freq[100100];
long long score[100100];
int cnt[100100];
long long ans[100100];
void dfs (int x, int p) {
	for (auto i: adj[x]) {
		if (i == p) continue;
		dfs(i, x);
	}
	ptr[x] = x;
	freq[x][color[x]] = 1;
	score[x] = color[x];
	cnt[x] = 1;
	for (auto i: adj[x]) {
		if (i == p) continue;
		if (freq[ptr[x]].size() < freq[ptr[i]].size()) {
			swap(ptr[x], ptr[i]);
		}
		for (auto &j: freq[ptr[i]]) {
			freq[ptr[x]][j.first] += j.second;
			if (freq[ptr[x]][j.first] > cnt[ptr[x]]) {
				cnt[ptr[x]] = freq[ptr[x]][j.first];
				score[ptr[x]] = j.first;
			} else if (freq[ptr[x]][j.first] == cnt[ptr[x]]) {
				score[ptr[x]] += j.first;
			}
		}
	}
	ans[x] = score[ptr[x]];
}
int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> color[i];
	}
	int ai, bi;
	for (int i=0; i<n-1; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		adj[ai].push_back(bi);
		adj[bi].push_back(ai);
	}
	dfs(0, 0);
	for (int i=0; i<n; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
}