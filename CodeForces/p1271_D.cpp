#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct castle {
	int ind;
	int cost;
	int hire;
	int imp;
};
int main () {
	int n, m, k;
	cin >> n >> m >> k;
	vector<castle> v;
	int a, b, c;
	for (int i=0; i<n; i++) {
		cin >> a >> b >> c;
		v.push_back({i, a, b, c});
	}
	vector< priority_queue< pair<int, int> > best;
	vector<int> left;
}