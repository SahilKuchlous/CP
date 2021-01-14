#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main () {
	int n;
	cin >> n;
	int seq_a[n], seq_b[n];
	for (int i=0; i<n; i++) {
		cin >> seq_a[i];
	}
	for (int i=0; i<n; i++) {
		cin >> seq_b[i];
	}
	vector< pair<long long, long long> > vals;
	long long sum_a, sum_b;
	for (int i=0; i<(1<<n); i++) {
		sum_a = sum_b = 0;
		for (int j=0; j<n; j++) {
			if (i & (1<<j)) {
				sum_a += seq_a[j];
			} else {
				sum_b += seq_b[j];
			}
		}
		vals.push_back(make_pair(sum_a, sum_b));
	}
	sort(vals.begin(), vals.end());
	vector< pair<long long, long long> > edge;
	pair<long long, long long> cur;
	for (int i=0; i<vals.size(); i++) {
		while (edge.size() > 0) {
			cur = edge.back();
			if (cur.first <= vals[i].first && cur.second <= vals[i].second) {
				edge.pop_back();
			} else {
				break;
			}
		}
		edge.push_back(vals[i]);
	}
	long long oa = 1e14, ob = 1e14;
	for (int i=0; i<edge.size()-1; i++) {
		cur.first = edge[i].first+1;
		cur.second = edge[i+1].second+1;
		if (cur.first+cur.second < oa+ob) {
			oa = cur.first;
			ob = cur.second;
		}
	}
	cout << oa << endl;
	cout << ob << endl;
}