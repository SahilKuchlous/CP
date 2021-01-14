#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <cmath>
using namespace std;
ifstream fin("visitfj.in");
ofstream fout("visitfj.out");
int n, t;
int cost[110][110];
map< int, set< pair<int, int> > > adj;
int main () {
	fin >> n >> t;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			fin >> cost[i][j];
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			/*
			if (i-3>=0) adj[i*100+j].insert(make_pair((i-3)*100+j, cost[i-3][j]+3*t));
			if (i-2>=0 && j+1<n) adj[i*100+j].insert(make_pair((i-2)*100+j+1, cost[i-2][j+1]+3*t));
			if (i-1>=0 && j+2<n) adj[i*100+j].insert(make_pair((i-1)*100+j+2, cost[i-1][j+2]+3*t));
			if (j+3<n) adj[i*100+j].insert(make_pair(i*100+j+3, cost[i][j+3]+3*t));
			if (i+1<n && j+2<n) adj[i*100+j].insert(make_pair((i+1)*100+j+2, cost[i+1][j+2]+3*t));
			if (i+2<n && j+1<n) adj[i*100+j].insert(make_pair((i+2)*100+j+1, cost[i+2][j+1]+3*t));
			if (i+3<n) adj[i*100+j].insert(make_pair((i+3)*100+j, cost[i+3][j]+3*t));
			if (i+2<n && j-1>=0) adj[i*100+j].insert(make_pair((i+2)*100+j-1, cost[i+2][j-1]+3*t));
			if (i+1<n && j-2>=0) adj[i*100+j].insert(make_pair((i+1)*100+j-2, cost[i+1][j-2]+3*t));
			if (j-3>=0) adj[i*100+j].insert(make_pair(i*100+j-3, cost[i][j-3]+3*t));
			if (i-1>=0 && j-2>=0) adj[i*100+j].insert(make_pair((i-1)*100+j-2, cost[i-1][j-2]+3*t));
			if (i-2>=0 && j-1>=0) adj[i*100+j].insert(make_pair((i-2)*100+j-1, cost[i-2][j-1]+3*t));
			*/
			for (int k=max(0, i-3); k<min(n, i+4); k++) {
				for (int l=max(0, j-3); l<min(n, j+4); l++) {
					if (abs(i-k)+abs(j-l) == 1 || abs(i-k)+abs(j-l) == 3) {
						adj[i*100+j].insert(make_pair(k*100+l, cost[k][l]+3*t));
					}
				}
			}
		}
	}
	long long min_dist[10100];
	set< pair<int, int> > ranks;
	min_dist[0] = 0;
	for (int i=1; i<10100; i++) {
		min_dist[i] = 1e12;
	}
	ranks.insert(make_pair(0, 0));
	set<int> vis;
	while (ranks.size() > 0) {
		int cur = ranks.begin()->second;
		ranks.erase(ranks.begin());
		vis.insert(cur);
		for (auto i: adj[cur]) {
			if (vis.find(i.first) == vis.end() && min_dist[cur]+i.second < min_dist[i.first]) {
				ranks.erase(make_pair(min_dist[i.first], i.first));
				ranks.insert(make_pair(min_dist[cur]+i.second, i.first));
				min_dist[i.first] = min_dist[cur]+i.second;
			}
		}
	}
	long long ans = min_dist[(n-1)*100+n-1];
	ans = min(ans, min_dist[(n-2)*100+n-1]+t);
	ans = min(ans, min_dist[(n-1)*100+n-2]+t);
	if (n-3 >= 0) ans = min(ans, min_dist[(n-3)*100+n-1]+2*t);
	ans = min(ans, min_dist[(n-2)*100+n-2]+2*t);
	if (n-3 >= 0) ans = min(ans, min_dist[(n-1)*100+n-3]+2*t);
	/*
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cout << min_dist[i*100+j] << " ";
		}
		cout << endl;
	}
	*/
	fout << ans << endl;
}