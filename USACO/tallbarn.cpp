#include <iostream>
#include <fstream>
#include <set>
#include <cmath>
#include <vector>
using namespace std;
ifstream fin("tallbarn.in");
ofstream fout("tallbarn.out");
int n;
long long k;
long long cost[100100];
vector<long long> cur_req;
vector<long long> best_req;
long long best_rem;
long long calc (double a, double x) {
	return ceil((-1+sqrt(1+4*a/x))/2);
}
long long check (double val) {
	long long cur_k = k;
	for (int i=0; i<n; i++) {
		long long req = calc(cost[i], val);
		cur_req.push_back(req);
		cur_k -= req-1;
	}
	return cur_k;
}
int main () {
	fin >> n >> k;
	for (int i=0; i<n; i++) {
		fin >> cost[i];
	}
	long long max_cost = 0;
	for (int i=0; i<n; i++) {
		max_cost = max(max_cost, cost[i]);
	}
	k -= n;
	double l = 0, u = max_cost, mid;
	while (u-l >= 0.00000000001) {
		cur_req.clear();
		mid = (l+u)/2;
		long long rem = check(mid);
		if (rem >= 0) {
			best_req = cur_req;
			best_rem = rem;
			u = mid;
		} else {
			l = mid;
		}
	}
	k = best_rem;
	double total = 0;
	multiset< pair< double, pair<double, double> >, greater< pair< double, pair<double, double> > > > cur;
	for (int i=0; i<n; i++) {
		total += 1.0*cost[i]/best_req[i];
		cur.insert(make_pair(1.0*cost[i]/best_req[i]-1.0*cost[i]/(best_req[i]+1), make_pair(cost[i], best_req[i])));
	}
	pair< double, pair<double, double> > m;
	for (int i=0; i<k; i++) {
		m = *(cur.begin());
		cur.erase(cur.begin());
		total -= m.first;
		m.second.second++;
		m.first = m.second.first/m.second.second-m.second.first/(m.second.second+1);
		cur.insert(m);
	}
	fout << (long long)round(total) << endl;
}